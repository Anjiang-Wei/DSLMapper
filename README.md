# DSLMapper
**DSL Mapper is tested on the `control_replication` branch of Legion.**
## Getting Started

### Downloading and Copying Files
```
git clone git@github.com:Anjiang-Wei/DSLMapper.git
cp -r DSLMapper/src/dsl_mapper.cc DSLMapper/src/dsl_mapper.h DSLMapper/src/compiler $your_project_source_dir
```
### Mapper Registration

#### For Legion Program
Register the [callback function](https://github.com/Anjiang-Wei/DSLMapper/blob/main/src/dsl_mapper.cc#L2096) to the Legion runtime.
The callback will invoke the [registration function](https://github.com/Anjiang-Wei/DSLMapper/blob/main/src/dsl_mapper.cc#L2026)

User can try the DSL mapper while having an existing customized C++ mapper, and we allow users to choose whether to choose DSL mapper or the original customized C++ mapper from command line (`-dslmapper`). This is function that we change for the [circuit mapper](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_mapper.cc#L453-L522) to support it.

In this way, users can choose whether to use DSL mapper by passing `-dslmapper` in the command line (without recompilation).
  
Besides, users can turn on [logging wrapper](https://legion.stanford.edu/debugging/#mapper-logging-wrapper) to record the mapping decisions by passing `-wrapper` in the command line.

#### For Regent Program
The original compilation flow needs to be customized in order to integrate DSL mapper:
  1) Allow warnings in compilation. Comment out the `-Werror` flags. Here is the change we make for the [circuit example](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L59-L60)
  2) Make sure the right mapper registration function is used. Here is the circuit example's [compilation script](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L812) and corresponding [registration function](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_mapper.cc#L548)

**Note**, using Legion's namespace and having user-defined typedef together could sometimes cause compilation problems. In DSL Mapper, we use `using namespace Legion; using namespace Legion::Mapping;` If it happens to collide with application code's typedef, users can change their code to be more specific about the namespace and the types, e.g., changing `Rect<3>` to `Legion::Rect<3,long long>`

## Language Design
Every statement in the program should end with `;` (like `C`)

Functions should start with `def FuncName(Arg1Type arg1, ...)` and the function body needs to be wrapped with `{ ... }`, e.g., used in [Index Task Placement](https://github.com/Anjiang-Wei/DSLMapper/#index-task-launch-placement)

Comments should start with `#` (like `Python`)

### Task Placement
```
Task foo CPU; # for task named "foo", run on CPU
Task * GPU,OMP,CPU; # for any other task, by default try running on GPU first (if a GPU variant exists), then try OpenMP Processor, finally try CPU.
```
The task named `foo` will use `CPU`. For other tasks, they will use the default (fallback) strategies.
The wildcard `*` is a way to describe fallback policies, after which is a priority-list of processors kinds.
The supported processor kinds are 
  - `CPU`: `Processor::LOC_PROC` in Legion
  - `GPU`: `Processor::TOC_PROC` in Legion
  - `OMP`: OpenMP, `Processor::OMP_PROC` in Legion
  - `IO`: `Processor::IO_PROC` in Legion
  - `PY`: Python, `Processor::PY_PROC` in Legion
  - `PROC`: `Processor::PROC_SET` in Legion 

Implementation:
`select_task_options`, `dsl_default_policy_select_initial_processor`, `validate_processor_mapping`
### Region Placement
There are two modes for Region placement. One is called semantic naming mode, and the other is called index-based mode.
To support semantic naming mode, you need to pass `-tm:use_semantic_name` in the command line when using DSL mapper.
```
Region * * GPU FBMEM; # for any tasks, any regions, if mapped onto GPU, use GPU FrameBuffer Memory as default
Region * * CPU SYSMEM; # for any tasks, any regions, if mapped onto CPU, use CPU System Memory as default

# for $task, $region, if mapped onto $proc_type, specify $mem_type to use
Region * rp_shared GPU ZCMEM;
Region * rp_ghost GPU ZCMEM;
```
To name the regions, users can attach semantic names (`runtime->attach_name`) to regions in Legion. Regent will automatically attach the variable names as the semantic names.

**Note**: for region names, we need to use the region names that are passed in (instead of the names used in task definition/declaration). The implication is that as long as the task uses the `rp_shared` region, no matter what argument name the task uses for declaration, the `rp_shared` region will be placed onto zero-copy memory. In the above example, since the task is a wildcard (`*`), all tasks using the `rp_shared` will be placed onto zero-copy memory.
In Regent, the semantic name binding happens when you invoke certain APIs (e.g., `partition`) and bind it to a variable, e.g., [`rp_shared`](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L744) and [`rp_ghost`](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L634) in the Circuit example. Typically, regions that are across the partition boundaries needs faster communication, and thus may benefit from placing onto ZCMEM.

Users can also choose to use index-based approach for placing regions (without passing `-tm:use_semantic_name` in command line).
```
Region foo 0 GPU ZCMEM; # If task foo is mapped onto GPU, place its first region onto ZeroCopy memory
```
The index is for `task.regions`, starting from 0.

The supported memory kinds are the following:
  - `SYSMEM` (`Memory::SYSTEM_MEM` in Legion)
  - `FBMEM` (`Memory::GPU_FB_MEM` in Legion, FrameBuffer Memory on GPU)
  - `ZCMEM` (`Memory::Z_COPY_MEM` in Legion, ZeroCopy Memory for GPU)
  - `RDMEM` (`Memory::REGDMA_MEM` in Legion, RDMA memory)
  - `SOCKMEM` (`Memory::SOCKET_MEM` in Legion)
  - `VIRTUAL` (`PhysicalInstance::get_virtual_instance()` in Legion, useful for inner tasks where no memory allocation is needed)

The DSL mapper's implementation will try to get the memory that has the highest bandwidth with the chosen processor and the specified memory kind. This can be important when one GPU has affinity with multiple `ZCMEM`, one `OMP` has affinity with multiple `SOCKMEM`, and our implementation will choose the best memory (i.e., the highest bandwidth) in those cases.

Implementation:
`map_task`, `get_handle_names`, `maybe_append_handle_name`, `dsl_default_policy_select_target_memory`, `query_best_memory_for_proc`
### Layout Constraint
```
# Task, Region, Processor Kind, List of Constraints
Layout * * * SOA C_order; # Other choices: AOS F_order Exact Align==128 Compact
``` 
- `SOA` refers to `Struct of Array` while `AOS` refers to `Array of Struct`. It is translated to `OrderingConstraint` in Legion.
- `C_order` and `F_order` are two different orderings. It is translated to `OrderingConstraint` in Legion.
- `Align` can specify memory alignment, and we support operators including `==`, `<=`, `>=`, `!=`. This corresponds to `AlignmentConstraint` in Legion. `OrderingConstraint` and `AlignmentConstraint` are useful because certain APIs from external libraries (e.g., CuBLAS) may require the data to be in a specific layout or the data to be aligned in memory.
- `Compact`: it is translated to `LEGION_COMPACT_SPECIALIZE` of `SpecializedConstraint`.
- `Exact`: it corresponds to `LEGION_COMPACT_SPECIALIZE` of `SpecializedConstraint` (setting `exact=true`). Users can also pass `-dm:exact_region` in command line to request exact region allocation (globally).

Implementation:
`map_task`, `dsl_default_create_custom_instances`, `dsl_default_policy_select_constraints`, `dsl_default_policy_select_layout_constraints`
### Backpressure
To turn on this feature, pass `-tm:enable_backpressure` in command line.
```
InstanceLimit task_4 1;
InstanceLimit task_6 1;
```
On each node, only one `task_4` can be mapped at the same time. Only one `task_6` can be mapped at the same time. Typically, tasks are mapped ahead of time, and backpressure can avoid mapping too many tasks at the same time ahead of time, which can avoid consuming too much memory. The above example comes from the mapping policy for [Cannon](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/cannonMM-cuda/mappings).

Implementation:
`select_tasks_to_map`, `map_task`, `map_task_post_function`, `report_profiling`, `get_mapper_sync_model`
 
The [backpressure example](https://github.com/StanfordLegion/legion/blob/stable/examples/mapper_backpressure/backpressure.cc) in Legion repository has more detailed explanation.
### Memory Collection
To turn on this feature, pass `-tm:untrack_valid_regions` in the command line.
```
# $task $region 
CollectMemory task_4 *;
```
`CollectMemory` can tell Legion runtime to untrack certain read-only regions as valid regions so that those memories can be collected (i.e., adding the region into  `untracked_valid_regions` in `MapTaskOutput` struct). This is useful when users know that certain read-only regions will only be used once for some tasks, and keeping the regions in memory costs too much memory consumption.
Here the region supports both semantic naming (if passing `-tm:use_semantic_name`), index naming (starting from `0`), and also wildcard (`*`).

Implementation:
`map_task`, `map_task_post_function`
### Index Task Launch Placement
```
mcpu = Machine(CPU); # 2-dim tuple: nodes * CPU processors, assuming one Legion runtime per node
mgpu = Machine(GPU); # 2-dim tuple: nodes * GPU processors, assuming one Legion runtime per node

def linearblock(Task task) {
    # task.ipoint is a n-dim tuple (in this case n=1) indicating index point within the index launch domain
    # task.ispace is a n-dim tuple (in this case n=1) indicating launch domain, not used here
    return mgpu[task.ipoint[0] / mgpu.size[1], task.ipoint[0] % mgpu.size[1]]; # return one point in a machine model
}

def block_shard_cpu(Task task) {
    return mcpu[task.ipoint[0] / mcpu.size[1], 0]; # only one CPU per node
}

# specify $task_name(s) and sharding+slicing function
IndexTaskMap calculate_new_currents,distribute_charge,update_voltages linearblock;
IndexTaskMap init_piece,init_pointers,print_summary block_shard_cpu;
```
`IndexTaskMap` can specify a list of comma-separated task names and the corresponding sharding+slicing functions to use. The above code snippet is from the [circuit example](https://github.com/Anjiang-Wei/legion/blob/example/language/pldi23_scripts/circuit_mappings).

On a high level, users want to map each N-dim point from the launch domain to a point in the machine model to pick the processor.
`Machine($PROC_KIND)` can be used to initialize a 2-dim machine model with respect to a processor kind. The initialized machine model is a 2-dim tuple, and we can access the number of nodes with `mcpu.size[0]` and the number of CPU processors in each node with `mcpu.size[1]`.

The function signature should always be taking one argument `Task`, and return one point in a machine model. Inside the function, users need to specify that for each index point, how to map the index point (`task.ipoint[0]` for 1d index launch) to one point in the machine model.
If turning on the logging wrapper, users can see the following logs running on a 2 node, 4 GPU per node machine:
```
SELECT_SHARDING_FUNCTOR for calculate_new_currents
0 <- (0) (1) (2) (3)
1 <- (4) (5) (6) (7)
```
The `SELECT_SHARDING_FUNCTOR` will report the decision of choosing nodes. The task `calculate_new_currents` mapped onto GPU will use `linearblock` function, and it corresponds to `task.ipoint[0] / mgpu.size[1]` for choosing nodes. Here each node has 4 GPUs, so it is `task.ipoint[0] / 4`.
```
SLICE_TASK for calculate_new_currents
<0>..<0> -> 1d00000000000003
<1>..<1> -> 1d00000000000004
<2>..<2> -> 1d00000000000005
<3>..<3> -> 1d00000000000006
```
The `SLICE_TASK` will report the decision of choosing processors within the node. The task `calculate_new_currents` will use `task.ipoint[0] % mgpu.size[1]` (i.e.,  `task.ipoint[0] % 4` in this case) so that within each node, each index point will be placed on a different GPU processor.

**Note**: if running multiple Legion runtimes per node, i.e., multiple ranks per node, then `mcpu.size[0]`, `mgpu.size[0]` becomes the number of ranks, and `mcpu.size[1]`, `mgpu.size[1]` becomes the number of processors within that rank.
 
Implementation:
`select_sharding_functor`, `shard`, `slice_task`, `dsl_slice_task`, `dsl_decompose_points`, etc.
### Machine Model Transformation
#### Merge
The `merge` transformation is a method supported on a machine model, and it takes two integers (`dim1`, `dim2`) as the arguments. The `dim1` and `dim2` dimensions will be merged into one dimension (`dim1` in the returned machine model) in the new machine model. Therefore, the returned machine model `model_new` will have one dimension smaller than `model_old`.
```
model_new = model_old.merge(dim1, dim2);
```
We can guarantee that:
-  The machine indexed by `model_new[..., i, ...]` (where `i` is at index `dim1`) is the same as `model_old[..., i / model_old.size[dim2], ..., i % model_old.size[dim2], ...]`, where `i / model_old.size[dim2]` appears at index `dim1` of the `model_old` and `i % model_old.size[dim2]` appears at index `dim2` of `model_old`.
- `model_new.size[dim1] == model_old.size[dim1] * model_old.size[dim2]`
- `model_new.size` will be a `N-1`-dim tuple if `model_old` is a `N`-dim tuple

A real example of the `merge` transformation is below, extracted from [solomonik](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/solomonikMM-cuda/mappings). In general, `merge` transformation can return a new machine model with fewer dimensions, which can be useful to index launches with lower dimensions.
```
m_2d = Machine(GPU); # nodes * processors
m_1d = m_2d.merge(0, 1);

def block_primitive(IPoint x, ISpace y, MSpace z, int dim1, int dim2) {
    return x[dim1] * z.size[dim2] / y.size[dim1];
}

def block1d(Task task) {
    return m_1d[block_primitive(task.ipoint, task.ispace, m_1d, 0, 0)];
}

IndexTaskMap init_cublas block1d;
```
The task `init_cublas` is a 1D index launch. The machine model `m_1d` is obtained by applying the `merge` transformation to the `m_2d` machine model. Then the it does a blockwise distribution. Here we define a function `block_primitive` which is a more general blockwise function that will be useful for later examples. It takes index point `IPoint x`, index space `ISpace y`, and machine model `MSpace z` as input, and also allows users to specify which dimensions of the index launch `int dim1` and which dimension of the machine model `int dim2` to be blockwise mapped. In this case, because both the machine model `m_1d` and the task's index launch (`task.ipoint`, `task.ispace`) are 1D, `dim1` and `dim2` are both set to `0`.

#### Split
The `split` transformation is a method supported on a machine model, and it takes two integers (`split_dim`, `split_factor`) as the arguments. The `split_dim` of the original machine model will be splitted into two dimensions `split_dim` (with size `split_factor`) and `split_dim+1`. Therefore, the returned machine model `model_new` will have one dimension bigger than `model_old`. You may think of `split` as a reverse transformation of `merge`.
```
model_new = model_old.split(split_dim, split_factor);
```
We can guarantee that:
-  The machine indexed by `model_new[..., i, j, ...]` (where `i`,`j` is at index `split_dim` and `split_dim+1`) is the same as `model_old[..., i + j * split_factor]`
- `model_new.size[split_dim] * model_new.size[split_dim+1] == model_old.size[split_dim]`
- `model_new.size[split_dim].size == split_factor`
- `model_new.size` will be a `N+1`-dim tuple if `model_old` is a `N`-dim tuple

Due to the more expressivity that [autosplit](#auto_split) provides, `split` transformation is not used quite often in practice.

#### Swap
The `swap` transformation is a method supported on a machine model, and it takes two integers (`dim1`, `dim2`) as the arguments. The returned machine model `model_new` will swap the two dimensions of `dim1` and `dim2`.
```
model_new = model_old.swap(dim1, dim2);
```
We can guarantee that:
-  The machine indexed by `model_new[..., i, ..., j, ...]` (where `i`,`j` is at index `dim1` and `dim2`) is the same as `model_old[..., j, ..., i, ...]`
- `model_new.size[dim1] == model_old.size[dim2]`
- `model_new.size[dim2].size == model_old.size[dim1]`
- `model_new.size` will be a `N`-dim tuple if `model_old` is a `N`-dim tuple

Due to the more expressivity that [autosplit](#auto_split) provides, `split` transformation is not used quite often in practice.

#### Auto_split
```
def block_primitive(IPoint x, ISpace y, MSpace z, int dim1, int dim2) {
    return x[dim1] * z.size[dim2] / y.size[dim1];
}

def cyclic_primitive(IPoint x, ISpace y, MSpace z, int dim1, int dim2) {
    return x[dim1] % z.size[dim2];
}

def auto3d(Task task) {
    m_4d = m_2d.auto_split(0, task.ispace); # split the original 0 dim into 0,1,2 dim
    # subspace: task.ispace / m_4d[:-1]
    m_6d = m_4d.auto_split(3, task.ispace / m_4d[:-1]); # split the processor (previosly 1, now 3) dim into 3,4,5 dim w.r.t subspace
    upper = tuple(block_primitive(task.ipoint, task.ispace, m_6d, i, i) for i in (0,1,2));
    lower = tuple(cyclic_primitive(task.ipoint, task.ispace, m_6d, i, i + 3) for i in (0,1,2));
    return m_6d[*upper, *lower];
}
IndexTaskMap task_5 auto3d; # task_5 launch space: (rpoc, rpoc, c)
```

Explanation: To be done.

Implementation:
  `MSpace.cc`
### Single Task Launch Placement
```
m_2d = Machine(GPU); # nodes * processors
def same_point(Task task) {
    return m_2d[*task.parent.processor(m_2d)]; # same point as its parent
}
SingleTaskMap task_4 same_point;
```
For tasks that are not index launch, users can also specify where to place tasks.
  
Typically, the default mapper will use some heuristic depending on the depth of the task (`task.get_depth()` in `default_policy_select_initial_processor`): round-robin *local* processors (within the same node) for top-level (0-level) tasks, round-robin all processors for 1-level tasks (beyond the same node) if not tagged with `SAME_ADDRESS_SPACE`, round-robin local processors (within the same node) of the same kind for 2-level task or deeper tasks. Different applications may want different strategies to get better data locality, and users can customize it with DSL mapper.

The above example code specifies that `task_4` will be placed on the same processor as its parent task (originating processsor). `task.parent` is another `Task` object, and `task.parent.processor(m_2d).processor(m_2d)` will return a tuple representing the position with respect to the machine model `m_2d`, e.g., (1, 1) means that `task_4`'s parent is placed on the second node's second GPU. `*` is used here to turn `(1, 1)` into `1, 1` with which we can use to index the `m_2d` again so that we place `task_4` on exactly the same processor as its parent. 

```
def same_node(Task task) {
    return m_2d[task.parent.processor(m_2d)[0], *]; # same node as its parent
}
```
Users can also specify `*` to specify a set of points in the machine model, to define a round-robin strategy. The above `same_node` function specifies that the task will be placed on the same node as its parent (`task.parent.processor(m_2d)[0]`), and any processor on that node (`*`) is acceptable. The runtime will make the choice dynamically.

## Full Examples
Conventional Legion Benchmarks
- [Circuit](https://github.com/Anjiang-Wei/legion/blob/example/language/pldi23_scripts/circuit_mappings)
- [Stencil](https://github.com/Anjiang-Wei/legion/blob/example/language/pldi23_scripts/stencil_mappings)
- [Pennant](https://github.com/Anjiang-Wei/legion/blob/example/language/pldi23_scripts/pennant_mappings)

Distributed GEMM Algorithms
- [Cannon](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/cannonMM-cuda/mappings)
- [Solomonik](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/solomonikMM-cuda/mappings)
- [Cosma](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/cosma-cuda/mappings)
- [Johnson](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/johnsonMM-cuda/mappings)

## Command Line Options

## Debugging Support

### Printing

### Mapper Logging Wrapper

## Limitations

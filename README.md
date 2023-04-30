# DSLMapper
**DSL Mapper is tested on the [`control_replication` branch](https://github.com/StanfordLegion/legion/tree/control_replication) of [Legion](https://legion.stanford.edu/).**

The resources for learning Legion's C++ mapping interface is on [Legion website](https://legion.stanford.edu/mapper/) and in [Legion manual, Chapter 7](https://legion.stanford.edu/pdfs/legion-manual.pdf)

## Content Overview

[Presentation](#presentation)

[Getting Started](#getting-started)

[Command Line Options](#command-line-options)

[Task Placement](#task-placement)

[Region Placement](#region-placement)

[Layout Constraint](#layout-constraint)

[Backpressure](#backpressure)

[Memory Collection](#memory-collection)

[Index Task Launch Placement (Sharding and Slicing)](#index-task-launch-placement)
- [Common pattern](#common-pattern)

[Machine Model Transformation](#machine-model-transformation)

- [merge](#merge)
- [split](#split)
- [swap](#swap)
- [slice](#slice)
- [reverse](#reverse)
- [balance_split](#balance_split)
- [auto_split](#auto_split)

[Single Task Launch Placement](#single-task-launch-placement)

[Full Examples](#full-examples)

[Debugging Support](#debugging-support)

## Presentation
1) [Slides](https://docs.google.com/presentation/d/1-fC2mVHgLc0nzO--iuB7t0KAdqKDBTsr/edit?usp=sharing&ouid=104017234541721380507&rtpof=true&sd=true) presented at Legion meeting
2) [Paper](https://drive.google.com/file/d/1m9o0SaHSSMqSPvMED_iDF_B4r9vUlKML/view?usp=share_link)

## Getting Started

### Downloading and Copying Files
```
git clone git@github.com:Anjiang-Wei/DSLMapper.git
cp -r DSLMapper/src/dsl_mapper.cc DSLMapper/src/dsl_mapper.h DSLMapper/src/compiler $your_project_source_dir
```
### Mapper Registration

#### For Legion Program
Register the [callback function](https://github.com/Anjiang-Wei/DSLMapper/blob/224d1e0239714d823d1a9d334a8eb5459f8a3e2d/src/dsl_mapper.cc#L2190) to the Legion runtime.
The callback will invoke the [function](https://github.com/Anjiang-Wei/DSLMapper/blob/224d1e0239714d823d1a9d334a8eb5459f8a3e2d/src/dsl_mapper.cc#L2120) to create mappers (i.e., replacing the default mapper).

Besides, users can turn on [logging wrapper](https://legion.stanford.edu/debugging/#mapper-logging-wrapper) to record the mapping decisions by passing `-wrapper` in the command line.

User can try the DSL mapper while having an existing customized C++ mapper, and we allow users to choose whether to choose DSL mapper or the original customized C++ mapper from command line (`-dslmapper`). This is function that we change for the [circuit mapper](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_mapper.cc#L453-L522) to support it.

In this way, users can choose whether to use DSL mapper by passing `-dslmapper` in the command line (without recompilation).

#### For Regent Program
The original compilation flow needs to be customized in order to integrate DSL mapper:
  1) Allow warnings in compilation. Comment out the `-Werror` flags. Here is the change we make for the [circuit example](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L59-L60)
  2) Make sure the right mapper registration function is used. Here is the circuit example's [compilation script](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L812) and corresponding [registration function](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_mapper.cc#L548)

**Note**, using Legion's namespace and having user-defined typedef together could sometimes cause compilation problems. In DSL Mapper, we use `using namespace Legion; using namespace Legion::Mapping;` If it happens to collide with application code's typedef, users can change their code to be more specific about the namespace and the types, e.g., changing `Rect<3>` to `Legion::Rect<3,long long>`

## Command Line Options

1) `-mapping mapping_file`: specify the mapping policy file (using the DSL). Updating the policy file does not need recompilation.
2) `-wrapper`: turn on [mapper logging wrapper](https://github.com/Anjiang-Wei/DSLMapper#mapper-logging-wrapper), for debugging purposes
3) `-tm:enable_backpressure`: turn on [backpressure](https://github.com/Anjiang-Wei/DSLMapper#backpressure)
4) `-tm:untrack_valid_regions`: turn on [memory collection](https://github.com/Anjiang-Wei/DSLMapper#memory-collection)
5) `-tm:use_semantic_name`: use semantic name instead of 0-based index to specify regions, explained in [region placement](https://github.com/Anjiang-Wei/DSLMapper#region-placement)
6) `-tm:select_source_by_bandwidth`: select sources for copies by bandwidth; the alternative option is to sort by the size of intersecting area. Refer to the implementation of the function `default_policy_select_sources` for details.

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

#### Common pattern
```
def block1d(Task task) {
    ip = task.ipoint;
    # is = task.ispace;
    return mgpu[ip[0] / mgpu.size[1], ip[0] % mgpu.size[1]];
}

def hierarchicalblock1d(Task task) {
    ip = task.ipoint;
    is = task.ispace;
    node_idx = ip[0] * mgpu.size[0] / is[0]; # block over node
    blk_size = is[0] / mgpu.size[0];
    gpu_ip = ip[0] % blk_size; # index within the node-partitioned block for mapping to GPU
    gpu_idx = gpu_ip * mgpu.size[1] / blk_size; # block over gpu
    return mgpu[node_idx, gpu_idx];
}
```
### Machine Model Transformation
#### Merge
The `merge` transformation is a method supported on a machine model, and it takes two integers (`dim1`, `dim2`) as the arguments. The `dim1` and `dim2` dimensions will be merged into the `dim1` dimension. More specifically, if `dim1 < dim2`, then the new merged dimension will be `dim1`; if `dim1 > dim2`, then the new merged dimension will be `dim1-1`. The returned machine model `model_new` will have one dimension smaller than `model_old`.
```
model_new = model_old.merge(dim1, dim2);
```
We can guarantee that:
- The merged dimension in the new machine model `merge_dim = dim1 < dim2 ? dim1 : (dim1 - 1)`
- We specify that `dim2` is the faster changing dimension during merging. More specifically, suppose the `model_old.size[dim2]` is `dim2_volume`. Then the processsor indexed by `model_new[..., i, ...]` where `i` is at index `merge_dim` refers to the same processor as indexing `model_old` with `i / dim2_volume` in `dim1` and `i % dim2_volume` in `dim2`.
- `model_new.size[merge_dim] == model_old.size[dim1] * model_old.size[dim2]`
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
-  The processor indexed by `model_new[..., i, j, ...]` (where `i`,`j` is at index `split_dim` and `split_dim+1`) is the same as `model_old[..., i + j * split_factor]`
- `model_new.size[split_dim] * model_new.size[split_dim+1] == model_old.size[split_dim]`
- `model_new.size[split_dim] == split_factor`
- `model_new.size` will be a `N+1`-dim tuple if `model_old` is a `N`-dim tuple

Due to the more expressivity that [autosplit](#auto_split) provides, `split` transformation is not used quite often in practice.

#### Swap
The `swap` transformation is a method supported on a machine model, and it takes two integers (`dim1`, `dim2`) as the arguments. The returned machine model `model_new` will swap the two dimensions of `dim1` and `dim2`.
```
model_new = model_old.swap(dim1, dim2);
```
We can guarantee that:
-  The processor indexed by `model_new[..., i, ..., j, ...]` (where `i`,`j` is at index `dim1` and `dim2`) is the same as `model_old[..., j, ..., i, ...]`
- `model_new.size[dim1] == model_old.size[dim2]`
- `model_new.size[dim2] == model_old.size[dim1]`
- `model_new.size` will be a `N`-dim tuple if `model_old` is a `N`-dim tuple

`swap` could be useful when the default ordering of `split` transformation is not what you expect. `swap` transformation is not used quite often in practice.

#### Slice
The `slice` transformation is a method supported on a machine model, and it takes three integers (`dim`, `low`, `high`) as the arguments. The returned machine model `model_new` will  be a machine model whose `dim` dimension only contains a subset of processors that ranges from `low` to `high` (both ends included), with other dimensions the same as `model_old`.
```
model_new = model_old.slice(dim, low, high);
```
We can guarantee that:
-  The processor indexed by `model_new[..., i, ...]` (where `i` is at index `dim`) is the same as `model_old[..., i + low, ...]`
- `model_new.size[dim] == high - low + 1`
- `model_new.size[other_dim] == model_old.size[other_dim]` (`other_dim` not equal to `dim`)
- `model_new.size` will be a `N`-dim tuple if `model_old` is a `N`-dim tuple

#### Reverse
The `reverse` transformation is a method supported on a machine model, and it takes one integers (`dim`) as the argument. The returned machine model `model_new` will  be a machine model whose `dim` dimension's index will be reversed.
```
model_new = model_old.reverse(dim);
```
We can guarantee that:
-  The processor indexed by `model_new[..., i, ...]` (where `i` is at index `dim`) is the same as `model_old[..., model_old.size[dim] - 1 - i, ...]`
- `model_new.size[any_dim] == model_old.size[any_dim]` the machine model's size does not change
- `model_new.size` will be a `N`-dim tuple if `model_old` is a `N`-dim tuple

We have not found a real use case for `reverse` so far. It could be useful when the processors are not exactly the same so that the order within the dimension would make a difference.


#### Balance_split
The `balance_split` transformation is a method supported on a machine model, and it takes two integers (`split_dim`, `num_dim`) as the arguments. The `split_dim` of the original machine model will be split into `num_dim` dimensions (i.e., splitting the original size of dimension`split_dim` into `split_dim`, `split_dim+1`, `split_dim+2` if `num_dim=3`). Therefore, the returned machine model `model_new` will have `num_dim-1` more dimensions  than `model_old`. The splitting is done in a "balanced"  way so that split dimensions' sizes are close to each other (as square/cubic as possible).
```
model_new = model_old.balance_split(split_dim, num_dim);
```
Let's see an example to understand how `balance_split` works.
Suppose `model_old.size[split_dim]=6`, applying `model_old.split(split_dim, 2)` will return a `model_new` satisfying `model_new.size[split_dim]=3` and `model_new.size[split_dim+1]=2`. There are two ways to factor 6:  $6=3 \times 2=6 \times 1$, and obviously the $6=3 \times 2$ is a more balanced way.

We also specify that the ordering in terms of the sizes of the newly created dimensions (`split_dim`, `split_dim+1`, `split_dim+2`) to be decreasing. Therefore, we will split 6 into 3X2 rather than 2X3. 

We can guarantee that:
- `model_new.size` will be a `N+num_dim-1`-dim tuple if `model_old` is a `N`-dim tuple

Due to the more expressivity that [autosplit](#auto_split) provides, `balance_split` transformation is not used quite often in practice. We only support `num_dim` to be `2` or `3` for now.

#### Auto_split

The `auto_split` transformation is a method supported on a machine model, and it takes an integer `dim` and a tuple of integers `vec` as the arguments. The `dim` of the original machine model will be split into more dimensions, which will be the same number of dimension of the tuple `vec`.
```
model_new = model_old.auto_split(dim, vec);
```
Suppose `vec` is a 3D tuple: `vec=(4,2,4)` and we want to split `model_old`'s `dim` dimension, for instance, `model_old.size[dim]=4`. The balanced way to split 32 into 3 numbers with respect to `(4,2,4)` is `4=2*1*2`. As a result, `model_new[dim]=2, model_new[dim+1]=1, model_new[dim+2]=2`.

Generally, given a N-dim tuple $vec=(L_1, L_2, ..., L_N)$,  `auto_split` aims to automatically split the `model_old`'s `dim` dimension of size  $O$ into a N-dim tuple $O_1, O_2, ..., O_N$ satifying the following property:
- $O_1 * O_2 * ... * O_N = O$
- Define  $W_i = \frac{L_i}{O_i}$. We guarantee that $\Sigma_{i \neq j} (W_i * W_j)$ is minimized


It can be proven that the minimum is achieved when $W_i$ are as close to each other as possible. In the above example, $(L_1,L_2,L_3)=(4,2,4)$, we split $O=4$ into $(O_1,O_2,O_3)=(2,1,2)$ such that $(W_1,W_2,W_3)=(\frac{L_1}{O_1}, \frac{L_2}{O_2}, \frac{L_3}{O_3}) = (2,2,2)$ are equal to each other.

This transformation primitive is quite useful in practice. If $dim$ represents the node dimension (i.e., $O$ is the number of nodes), and $vec$ is the task's index launch  domain, and `auto_split` can minimize inter-node communication assuming stencil computation pattern.

We can guarantee that:

- `model_new.size` will be a `N+vec.len`-dim tuple if `model_old` is a `N`-dim tuple

Below is a real use case for `auto_split`, extracted from [solomonik](https://github.com/Anjiang-Wei/taco/blob/distal-pldi-2022/build/solomonikMM-cuda/mappings)

```
def block_primitive(IPoint x, ISpace y, MSpace z, int dim1, int dim2) {
    return x[dim1] * z.size[dim2] / y.size[dim1];
}

def cyclic_primitive(IPoint x, ISpace y, MSpace z, int dim1, int dim2) {
    return x[dim1] % z.size[dim2];
}

m_2d = Machine(GPU); # nodes * processors
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

The first transformation is done via `m_2d.auto_split(0, task.ispace)` where `0` stands for the node dimension of the original machine model, and`task.ispace` is a tuple of integers representing the launch domain. The launch domain is 3D, so the original dimension 0 will be split into 3 dimensions, so the resulting machine model is `m_4d`, and its last dimension (dimension 3) corresponds to `m_2d`'s last dimension (dimension 1, representing processors per node).

Imagine that the launching domains will be mapped onto the nodes, and each node will get a subset of the index points. The tuple which represents each nodes' workload can be computed as another tuple: `task.ispace / m_4d[:-1]` . Here we use `m_4d[:-1]` to get the first dimensions of a machine model as a tuple of integers, and we directly support `/` operator for two tuple of integers.

To express the mapping more easily, we need `m_4d.auto_split(3, task.ispace / m_4d[:-1])` to obtain a 6D machine model. Here we split the last dimension (`3`) of `m_4d`, with respect to the workload tuple.

It's not hard to intuitively understand the resulting 6D machine model -- the first 3 dimensions correspond to node dimension, and the last 3 dimensions correspond to the processor dimension. For each point in the launching domain, we choose nodes in a blockwise way while we choose processors in a cyclic way. The way to specify this is to compute the `upper` 3D tuple and `lower` 3D tuple respectively with`tuple` construction, user-defined functions (`block_primitive` and `cyclic_primitive`). The syntax (`tuple`, `for`) is similar to [Python's list comprehension](https://python101.pythonlibrary.org/chapter6_comprehensions.html#list-comprehensions)

Finally, we can use `*` operator to turn a tuple of integers into integers (e.g., unwrapping `(1,2,1)` into `1,2,1`) for indexing the machine model to pick a specific processor via `m_6d[*upper, *lower]`.

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


## Debugging Support

### Print

Users can write print statement and `{}` in the language. The number of `{}` and the arguments for printing needs to match.
```
print("{}, {}, {}", a, b, c);
```

### Mapper Logging Wrapper
Users can inspect the mapping decisions by turning on logging wrapper via command line (`-wrapper`). An example log is [circuit](https://github.com/Anjiang-Wei/DSLMapper/blob/main/tool/circuit.wrapper), and [more logs](https://github.com/Anjiang-Wei/DSLMapper/tree/main/tool) are collected for reference

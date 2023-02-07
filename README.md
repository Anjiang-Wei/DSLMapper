# DSLMapper
## Getting Started

### Downloading and Copying Files
```
git clone git@github.com:Anjiang-Wei/DSLMapper.git
cp -r DSLMapper/src/dsl_mapper.cc DSLMapper/src/dsl_mapper.h DSLMapper/src/compiler $your_project_source_dir
```
### Mapper Registration

#### For Legion Program
Register the function to the Legion runtime:
[void register_mappers()](https://github.com/Anjiang-Wei/DSLMapper/blob/main/src/dsl_mapper.cc#L2096)
which will invoke the registration function:

[void NSMapper::create_mappers(Machine machine, Runtime *runtime, const std::set<Processor> &local_procs)](https://github.com/Anjiang-Wei/DSLMapper/blob/main/src/dsl_mapper.cc#L2026)

User can try the DSL mapper while having an existing customized C++ mapper, and we allow users to choose whether to choose DSL mapper or the original customized C++ mapper from command line (`-dslmapper`). This is function that we change for the [circuit mapper](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_mapper.cc#L453-L522) to support it.

In this way, users can choose whether to use DSL mapper by passing `-dslmapper` in the command line (without recompilation).
  
Besides, users can turn on [logging wrapper](https://legion.stanford.edu/debugging/#mapper-logging-wrapper) to record the mapping decisions by passing `-wrapper` in the command line.

#### For Regent Program
The original compilation flow needs to be customized in order to integrate DSL mapper:
  1) Allow warnings in compilation. Comment out the `-Werror` flags. Here is the change we make for the [circuit example](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L59-L60)
  2) Make sure the right mapper registration function is used. Here is the circuit example's [compilation script](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L812) and corresponding [registration function](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_mapper.cc#L548)

## Language Design

### Task Placement
```
Task foo CPU; # for task named "foo", run on CPU
Task * GPU,OMP,CPU; # for any other task, by default try running on GPU first (if a GPU variant exists), then try OpenMP Processor, finally try CPU.
```
The task named `foo` will use `CPU`. For other tasks, they will use the default (fallback) strategies.
The wildcard `*` is a way to describe fallback policies, after which is a priority-list of processors kinds.
The supported processor kinds are `CPU`, `GPU`, `OMP` (OpenMP), `IO`, `PY` (Python), `PROC` (Proc set)

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
In Regent, the semantic name binding happens when you invoke certain APIs (e.g., `partition`) and bind it to a variable, e.g., [`rp_shared`](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L744) and [`rp_ghost`](https://github.com/Anjiang-Wei/legion/blob/example/language/examples/circuit_sparse.rg#L634) in the Circuit example.

Users can also choose to use index-based approach for placing regions (without passing `-tm:use_semantic_name` in command line).
```
Region foo 0 GPU ZCMEM; # If task foo is mapped onto GPU, place its first region onto ZeroCopy memory
```
The index is for `task.regions`, starting from 0.

The supported memory kinds are the following:
  - `SYSMEM` (`Memory::SYSTEM_MEM` in Legion)
  - `FBMEM` (`Memory::GPU_FB_MEM` in Legion, FrameBuffer Memory on GPU)
  - `ZCMEM` (`Memory::Z_COPY_MEM` in Legion, ZeroCopy Memory for GPU), `RDMEM` (`Memory::REGDMA_MEM` in Legion, or RDMA memory)
  - `SOCKMEM` (`Memory::SOCKET_MEM` in Legion)
  - `VIRTUAL` (`PhysicalInstance::get_virtual_instance()` in Legion, useful for inner tasks where no memory allocation is needed)

The DSL mapper's implementation will try to get the memory that has the highest bandwidth with the chosen processor and the specified memory kind. This can be important when one GPU has affinity with multiple `ZCMEM`, one `OMP` has affinity with multiple `SOCKMEM`, and our implementation will choose the best memory (i.e., the highest bandwidth) in those cases.

Implementation:
`map_task`, `get_handle_names`, `maybe_append_handle_name`, `dsl_default_policy_select_target_memory`, `query_best_memory_for_proc`
### Layout Constraint

### Backpressure

### Memory Collection

### Index Task Launch Placement

### Machine Model Transformation

### Single Task Launch Placement

## Circuit Example

## Command Line Options

## Debugging Support

### Printing

### Mapper Logging Wrapper

## Limitations

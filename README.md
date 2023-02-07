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
Task * GPU,CPU; # for any task, run on GPU if a GPU variant exists, otherwise run on CPU
```
The task named `foo` will use `CPU`. For other tasks, they will use the default (fallback) strategies.
The wildcard `*` is a way to describe fallback policies, after which is a priority-list of processors kinds.
The supported processor kinds are `CPU`, `GPU`, `OMP` (OpenMP), `IO`, `PY` (Python), `PROC` (Proc set)

It is implemented by overriding `select_task_options`, and a helper function `dsl_default_policy_select_initial_processor`, `validate_processor_mapping`.
### Region Placement

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

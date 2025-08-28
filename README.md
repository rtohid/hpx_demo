## HPX

- Asynchronous many-task (AMT) runtime system
    - Threading system
    - Parcel port layer (communication through MPI, LCI, TCP)
    - Active Global Address Space AGAS
    - Local Control Objects (remote objects)
    - performance counter framework

- Parallelism and concurrency APIs:
    - future/async ([ex](02_future_simple.cpp))
    - continuation ([ex-1](03_future_then.cpp), [ex-2](04_when_all.cpp), [ex-3](05_wait_all.cpp))
    - dataflow )
    - parallel algorithms (all c++ std algorithms), supporting the following execution policies. ([ex](07_for_each_par.cpp))
      - seq: sequential
      - par: parallel
      - unseq: SIMD
      - par_unseq parallel+SIMD
    - parallel tasks ([ex-1](08_parallel_tasks.cpp), [ex-2](09_parallel_tasks_with_return.cpp))
    - co_routines ([ex](10_co_wait.cpp))
    - remote function calls ([ex](11_remote_call.cpp))
        - there's also remote objects

- commandline tools
    - `--hpx:threads=n`
    - `--hpx:list-counters`
        - `--hpx:print-counter=...`

## resources
- [repo](https://github.com/STEllAR-GROUP/hpx)
- [HPX documentation](https://hpx-docs.stellar-group.org/latest/html/index.html)
- [more examples](https://github.com/STEllAR-GROUP/hpx/tree/master/examples)
- [SLACK](https://discord.gg/Tn9QuzVjvy)
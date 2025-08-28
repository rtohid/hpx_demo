cmake_minimum_required(VERSION 3.25)
project(hpx_demo CXX)

find_package(HPX REQUIRED)

set(HPX_DEMO_SOURCES
    01_hello_world.cpp
    02_future_simple.cpp
    03_future_then.cpp
    04_when_all.cpp
    05_wait_all.cpp
    06_dataflows.cpp
    07_for_each_par.cpp
    08_parallel_tasks.cpp
    09_parallel_tasks_with_return.cpp
    10_co_wait.cpp
    11_remote_call.cpp
)

foreach(src ${HPX_DEMO_SOURCES})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
    target_link_libraries(${exe}
        HPX::hpx
        HPX::wrap_main
        HPX::iostreams_component
    )
endforeach()


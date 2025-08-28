#include <hpx/hpx_main.hpp>
#include <hpx/future.hpp>
#include <iostream>

int main()
{
    // launch a task
    hpx::future<int> f = hpx::async([]() { return 42; });

    // you can run other things in the meantime

    // `.get` blocks until the result is ready and retrieved
    std::cout << "f is " << f.get() << std::endl;
    return 0;
}


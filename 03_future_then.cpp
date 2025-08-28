#include <hpx/hpx_main.hpp>
#include <hpx/future.hpp>
#include <iostream>

int main()
{
    hpx::future<double> pi = hpx::async([](){ return 3.14; });

    // attach a continuation
    hpx::future<double> result = pi.then([](hpx::future<double>&& pi_c){
        return pi_c.get() * 10;
    });

    // non-blocking readiness check
    std::cout << "result ready? " << std::boolalpha << result.is_ready() << std::endl;

    // now block and print the value.
    std::cout << "value: " << result.get() << std::endl;
    return 0;
}


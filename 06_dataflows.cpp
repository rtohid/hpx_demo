#include <hpx/hpx_main.hpp>
#include <hpx/future.hpp>
#include <iostream>

int main()
{
    hpx::future<double> f_pi = hpx::async([](){ return 3.14; });
    hpx::future<double> f_r  = hpx::make_ready_future(42.0);

    // dataflow waits for futures and passes values to the lambda - no more tuples
    hpx::future<double> area = hpx::dataflow(
        [](hpx::future<double> pi, hpx::future<double> r){
            double pi_ = pi.get();
            double radius = r.get();
            return pi_ * radius * radius;
        },
        f_pi, f_r
    );

    std::cout << "area = " << area.get() << std::endl;
    return 0;
}


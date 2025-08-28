#include <hpx/hpx_main.hpp>
#include <hpx/future.hpp>
#include <hpx/tuple.hpp>
#include <iostream>

int main()
{
    hpx::future<double> f_pi = hpx::async([](){ return 3.14; });
    hpx::future<double> f_r  = hpx::async([](){ return 42.0; });

    // returns a single future that becomes ready when both inputs are ready
    double area =
        hpx::when_all(f_pi, f_r)
            .then([](hpx::future<
                        hpx::tuple<hpx::future<double>, hpx::future<double>>> f) {
                auto t  = f.get();
                double pi = hpx::get<0>(t).get();
                double r  = hpx::get<1>(t).get();
                return pi * r * r;
            })
            .get(); // wait here and return the computed value

    std::cout << "area = " << area << std::endl;
    return 0;
}


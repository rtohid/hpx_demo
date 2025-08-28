#include <hpx/hpx_main.hpp>
#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>

#include <vector>
#include <cstdlib>
#include <iostream>

int main()
{
    std::vector<int> v(1000000);

    hpx::generate(hpx::execution::seq, std::begin(v), std::end(v), &std::rand);

    // launch sort in parallel AND asynchronously
    hpx::future<void> done =
        hpx::sort(hpx::execution::par(           // parallel
                          hpx::execution::task), // ...and task-based (async)
                  std::begin(v), std::end(v));


    // you can run other things in the meantime

    std::cout << "sorted (future ready = " << std::boolalpha << done.is_ready() << ")\n";
    done.wait();
    std::cout << "sorted (future ready = " << std::boolalpha << done.is_ready() << ")\n";
    return 0;
}


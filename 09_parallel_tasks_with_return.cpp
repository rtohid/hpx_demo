#include <hpx/hpx_main.hpp>
#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};

    auto fut = hpx::count_if(
        hpx::execution::par(hpx::execution::task),
        v.begin(), v.end(),
        [](int x){ return x % 2 == 0; }
    );

    auto cnt = fut.get();
    std::cout << "even count = " << cnt << std::endl;
    return 0;
}


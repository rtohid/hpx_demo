#include <hpx/hpx_main.hpp>
#include <hpx/future.hpp>
#include <hpx/iostream.hpp>
#include <thread>
#include <chrono>

// coroutine
hpx::future<int> compute()
{
    hpx::cout << "[co] starting\n" << std::flush;

    auto f = hpx::async([]{
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        return 21;
    });

    int x = co_await f;     // suspend until ready
    co_return x * 2;
}

int main()
{
    hpx::future<int> result = compute();

    hpx::cout << "[main] doing other work\n" << std::flush;
    int v = result.get();
    hpx::cout << "[main] got result " << v << "\n" << std::flush;
}


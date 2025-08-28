#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>
#include <hpx/future.hpp>

#include <thread>
#include <vector>

int main()
{

    std::vector<hpx::future<void>> tasks;

    for (int i = 0; i < 8; ++i)
    {
        tasks.push_back(hpx::async([i]() {
            hpx::cout << "Hello from task " << i
                      << " on OS-thread " << std::this_thread::get_id()
                      << "\n" << std::flush;
        }));
    }

    hpx::wait_all(tasks);

    return 0;
}


#include <hpx/runtime_distributed.hpp>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>
#include <hpx/future.hpp>
#include <vector>

// function to run on each locality
void hello_world_foreman()
{
    std::uint32_t my_id = hpx::get_locality_id();
    hpx::cout << "Hello from locality " << my_id
              << " (global id: " << hpx::find_here() << ")\n"
              << std::flush;
}

// wrap the function as a plain action
HPX_PLAIN_ACTION(hello_world_foreman, hello_world_foreman_action);

int main()
{
    // get all participating localities (includes the current one)
    std::vector<hpx::id_type> localities = hpx::find_all_localities();

    // launch the action on each locality
    std::vector<hpx::future<void>> futures;
    futures.reserve(localities.size());
    for (hpx::id_type const& node : localities)
    {
        using action_type = hello_world_foreman_action;
        futures.push_back(hpx::async<action_type>(node));
    }

    // wait for all remote/local invocations to finish
    hpx::wait_all(futures);
    return 0;
}


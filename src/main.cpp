#include <hpx/hpx_main.hpp>
#include <hpx/include/components.hpp>
#include <hpx/iostream.hpp>
#include "hello_component.hpp"

int main()
{
  // Create an instance of the hello_component on the current locality (node)
  hpx::id_type hello_id = hpx::new_<hello_component>(hpx::find_here()).get();

  // Invoke the get_42 action
  hello_component::get_42_action get_42;
  int64_t result = get_42(hello_id);

  // Output the result
  hpx::cout << "The answer is: " << result << "\n"
            << std::flush;

  return 0;
}

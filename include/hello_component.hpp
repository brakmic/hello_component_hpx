#ifndef HELLO_COMPONENT_HPP
#define HELLO_COMPONENT_HPP

#include <hpx/include/components.hpp>
#include <hpx/include/actions.hpp>

class hello_component : public hpx::components::component_base<hello_component>
{
public:
  // Constructor
  hello_component() = default;

  // Action: Return the number 42
  int64_t get_42() const;

  // Define the action for HPX runtime
  HPX_DEFINE_COMPONENT_ACTION(hello_component, get_42);
};

HPX_REGISTER_ACTION_DECLARATION(hello_component::get_42_action, hello_component_get_42_action);

#endif // HELLO_COMPONENT_HPP

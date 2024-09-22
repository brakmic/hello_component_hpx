#include "hello_component.hpp"

int64_t hello_component::get_42() const
{
  return 42;
}

HPX_REGISTER_COMPONENT(hpx::components::component<hello_component>, hello_component);
HPX_REGISTER_ACTION(hello_component::get_42_action, hello_component_get_42_action);

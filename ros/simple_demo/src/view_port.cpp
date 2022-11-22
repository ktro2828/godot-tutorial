#include "simple_demo/view_port.hpp"

void ViewPort::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("pubImage"), &ViewPort::pubImage);
  ClassDB::bind_method(D_METHOD("spin_some"), &ViewPort::spin_some);
}

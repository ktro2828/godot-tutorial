#include "simple_demo/cmd_listener.hpp"

void CmdListener::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_cmd"), &CmdListener::get_cmd);
  ClassDB::bind_method(D_METHOD("spin_some"), &CmdListener::spin_some);
}

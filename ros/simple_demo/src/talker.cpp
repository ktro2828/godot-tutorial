#include "simple_demo/talker.hpp"

void Talker::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("talk", "cound"), &Talker::talk);
  ClassDB::bind_method(D_METHOD("spin_some"), &Talker::spin_some);
}

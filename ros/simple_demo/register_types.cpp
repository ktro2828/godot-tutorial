#include "register_types.h"

#include <core/class_db.h>

#include "simple_demo/talker.hpp"
#include "simple_demo/cmd_listener.hpp"
#include "simple_demo/view_port.hpp"


void register_simple_demo_types() {
  ClassDB::register_class<Talk>();
  ClassDB::register_class<ViewPort>();
  ClassDB::register_class<CmdListener>();
}

void unregister_simple_demo_types() {
  // Nothing to do here in this example.
}

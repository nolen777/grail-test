//
// Created by Dan Crosby on 9/28/23.
//

#include "print_hello.hpp"
#include "src/main/protobuf/test.pb.h"

int main(int argc, char* argv[]) {
  print_hello();

  auto msg = new grailtest::proto::TestProto();
  msg->set_dummy_field(15);
}
/* Copyright [2019] <thomas: mrqiantao@163.com> */
#include <iostream>
#include "example/example.h"

int main(int argc, char const *argv[]) {
  ::example::Example example;
  std::cout << example.DebugMessage() << std::endl;
  return 0;
}

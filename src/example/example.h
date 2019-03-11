/* Copyright [2019] <thomas: mrqiantao@163.com> */
#ifndef SRC_EXAMPLE_EXAMPLE_H_
#define SRC_EXAMPLE_EXAMPLE_H_
#include <string>

namespace example {
class Example {
 public:
  Example() : member_value_(666) {}
  std::string DebugMessage();

 private:
  int member_value_;
};
}  // namespace example

#endif  // SRC_EXAMPLE_EXAMPLE_H_

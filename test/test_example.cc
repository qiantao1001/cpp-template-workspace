/* Copyright [2019] <thomas: mrqiantao@163.com> */
#include "gtest/gtest.h"
#include "example/example.h"

TEST(ExampleTest, DebugMessage) {
  example::Example example;
  EXPECT_EQ(example.DebugMessage(), std::string("666"));
}

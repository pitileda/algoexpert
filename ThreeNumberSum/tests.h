#pragma once

#include <iostream>

#include "gtest/gtest.h"
#include "task.h"

struct TestDataItem {
  std::vector<int> inParam1;
  int inParam2;
  std::vector<std::vector<int>> expected;
};

std::vector<TestDataItem> test_data = {
    {{12, 3, 1, 2, -6, 5, -8, 6}, 0, {{-8, 2, 6}, {-8, 3, 5}, {-6, 1, 5}}}};

class TaskTest : public ::testing::TestWithParam<TestDataItem> {};

TEST_P(TaskTest, Tests) {
  const auto& data = GetParam();
  std::vector<std::vector<int>> result =
      threeNumberSum(data.inParam1, data.inParam2);
  EXPECT_EQ(result, data.expected);
  std::cout << '{';
  for (auto&& i : data.expected) {
    std::cout << " {";
    for (auto&& j : i) {
      std::cout << j << ",";
    }
    std::cout << "},";
  }
  std::cout << '\b';
  std::cout << " }\n";
}

INSTANTIATE_TEST_SUITE_P(Values, TaskTest, ::testing::ValuesIn(test_data));
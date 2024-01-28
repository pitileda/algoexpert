#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "gtest/gtest.h"
#include "solution.h"

TEST(Test, Test1) {
  std::vector<int> data{3, 5, -4, 8, 11, 1, -1, 6};
  std::set<int> res{11, -1};

  auto out = twoNumberSum(data, 10);
  EXPECT_EQ(res.size(), out.size());
  for (const auto& i : out) {
    EXPECT_NE(out.end(), std::find(out.begin(), out.end(), i));
  }
  std::cout << "[";
  for (auto&& i : out) {
    std::cout << i << ",";
  }
  std::cout << '\b';
  std::cout << "]\n";
}
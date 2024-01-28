#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"
#include "tests.h"
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  std::unordered_map<int, int> values;
  for (auto i = 0; i < array.size(); ++i) {
    for (auto j = i + 1; j < array.size(); ++j) {
      if (targetSum - array[i] == array[j]) {
        values[array[i]] = array[j];
      }
    }
  }
  std::vector<int> res;
  for (const auto& pair : values) {
    res.push_back(pair.first);
    res.push_back(pair.second);
  }
  return res;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
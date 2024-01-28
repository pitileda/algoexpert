#include <solution.h>

#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "tests.h"
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  std::unordered_set<int> nums;
  for (size_t i = 0; i < array.size(); i++) {
    if (nums.find(targetSum - array[i]) != nums.end()) {
      return {targetSum - array[i], array[i]};
    }
    nums.insert(array[i]);
  }
  return {};
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
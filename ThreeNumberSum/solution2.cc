#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "task.h"
#include "tests.h"

using namespace std;
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(), array.end(), less());
  vector<vector<int>> res;

  for (size_t i = 0; i < array.size(); i++) {
    size_t left = i + 1;
    size_t right = array.size() - 1;
    while (left < right) {
      int currSum = array[i] + array[left] + array[right];
      if (currSum == targetSum) {
        res.push_back({array[i], array[left], array[right]});
        left++;
        right--;
      }
      if (currSum < targetSum) {
        left++;
      }
      if (currSum > targetSum) {
        right--;
      }
    }
  }
  return res;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

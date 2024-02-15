#include <cstdint>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  unordered_map<int, vector<vector<int>>> sum_numbers;
  vector<vector<int>> quadros;
  for (uint32_t i = 1; i < array.size() - 1; ++i) {
    // iterate right from the current number
    for (uint32_t j = i + 1; j < array.size(); ++j) {
      int currSum = array[i] + array[j];
      int diff = targetSum - currSum;
      if (auto is = sum_numbers.find(diff); is != sum_numbers.end()) {
        for (const auto& pair : (*is).second) {
          vector<int> copy = pair;
          copy.push_back(array[i]);
          copy.push_back(array[j]);
          quadros.push_back(copy);
        }
      }
    }
    // iterate left from the current number
    for (uint32_t k = 0; k < i; k++) {
      int currSum = array[i] + array[k];
      if (auto is = sum_numbers.find(currSum); is != sum_numbers.end()) {
        sum_numbers[currSum].push_back({array[k], array[i]});
      } else {
        sum_numbers[currSum] = {{array[k], array[i]}};
      }
    }
  }
  return quadros;
}

TEST(My, Positive) {
  vector<vector<int>> res{{7, 6, 4, -1}, {7, 6, 1, 2}};
  EXPECT_EQ(res, fourNumberSum({7, 6, 4, -1, 1, 2}, 16));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

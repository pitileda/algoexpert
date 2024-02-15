#include <algorithm>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "task.h"
#include "tests.h"

using namespace std;
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // 1, {2,3,4,5}
  // pairSum = targetSum - curr
  set<set<int>> res;
  for (size_t i = 0; i < array.size(); i++) {
    int pairSum = targetSum - array[i];
    unordered_set<int> numbers;
    // curr = array[j]
    // pairSum - curr
    for (size_t j = 0; j < array.size(); j++) {
      if (i == j) {
        continue;
      }
      if (numbers.find(pairSum - array[j]) != numbers.end()) {
        res.insert({array[i], pairSum - array[j], array[j]});
      }
      numbers.insert(array[j]);
    }
  }

  vector<vector<int>> out;

  for (auto&& innerSet : res) {
    std::vector<int> innerVec(std::make_move_iterator(innerSet.begin()),
                              std::make_move_iterator(innerSet.end()));
    out.push_back(innerVec);
  }

  return out;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

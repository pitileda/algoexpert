#include <solution.h>

#include <map>
#include <set>
#include <vector>

#include "gtest/gtest.h"
#include "tests.h"
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  map<int, int> res{};
  std::set<int> possibleNumbers(array.begin(), array.end());
  for (auto it = possibleNumbers.begin(); it != possibleNumbers.end(); ++it) {
    if (next(it) == possibleNumbers.end()) {
      break;
    }
    auto inner_it = next(it);
    for (; inner_it != possibleNumbers.end(); ++inner_it) {
      if (*it + *inner_it == targetSum) {
        res[*it] = *inner_it;
      }
    }
  }
  possibleNumbers.clear();
  for (const auto& item : res) {
    possibleNumbers.insert(item.first);
    possibleNumbers.insert(item.second);
  }
  return std::vector<int>(possibleNumbers.begin(), possibleNumbers.end());
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
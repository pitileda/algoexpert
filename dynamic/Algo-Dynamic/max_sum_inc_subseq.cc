#include <cassert>
#include <iostream>
#include <list>
#include <optional>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  // Write your code here.
  if (array.size() == 0) {
    return {{}, {}};
  }

  if (array.size() == 1) {
    return {{array[0]}, {array[0]}};
  }

  std::vector<int> sums(array.size(), 0);
  std::vector<optional<int>> indexes(array.size(), nullopt);
  pair<int, int> max_sum{array[0], 0};  // sum, ind
  sums[0] = array[0];
  cout << sums.size() << endl;
  cout << indexes.size() << endl;
  for (int i = 1; i < array.size(); ++i) {
    sums[i] = array[i];
    for (int j = i - 1; j >= 0; --j) {
      if (array[j] >= array[i]) {
        continue;
      }
      if ((sums[j] + array[i]) > sums[i]) {
        sums[i] = sums[j] + array[i];
        indexes[i] = j;
      }
    }
    if (sums[i] > max_sum.first) {
      max_sum.first = sums[i];
      max_sum.second = i;
    }
  }
  list<int> sub{array[max_sum.second]};
  int it = max_sum.second;
  while (indexes[it] != nullopt) {
    sub.push_front(array[indexes[it].value()]);
    it = indexes[it].value();
  }
  return {
      {max_sum.first},           // Sum of sequence.
      {sub.begin(), sub.end()},  // Elements of the sequence.
  };
}

int main() {
  // vector<int> arr{10, 70, 20, 30, 50, 11, 30};
  vector<int> arr{8, 12, 2, 3, 15, 5, 7};
  vector<vector<int>> result = maxSumIncreasingSubsequence(arr);

  // Expected sum and subsequence
  int expected_sum = 35;
  vector<int> expected_subseq{8, 12, 15};

  // Assertions
  cout << result[0][0] << endl;
  for (const auto& i : result[1]) {
    cout << i << " ";
  }
  cout << endl;
  assert(result[0][0] == expected_sum && "Sum does not match expected value.");
  assert(result[1] == expected_subseq &&
         "Subsequence does not match expected sequence.");
  return 0;
}

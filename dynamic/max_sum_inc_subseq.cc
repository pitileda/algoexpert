#include <cassert>
#include <iostream>
#include <list>
#include <optional>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  // Write your code here.
  std::vector<int> sums(array.size(), 0);
  std::vector<optional<int>> indexes(array.size(), nullopt);
  pair<int, optional<int>> max_sum{0, nullopt};  // sum, ind
  sums[0] = array[0];
  cout << sums.size() << endl;
  cout << indexes.size() << endl;
  for (int i = 1; i < array.size(); ++i) {
    int current_sum = array[i];
    for (int j = i - 1; j >= 0; --j) {
      if (array[j] < array[i] && (sums[j] + current_sum) > current_sum) {
        current_sum += sums[j];
        indexes[i] = j;
        sums[i] = current_sum;
      }
    }
    if (current_sum > max_sum.first) {
      max_sum.first = current_sum;
      max_sum.second = i;
    }
  }
  list<int> sub{array[max_sum.second.value()]};
  int it = max_sum.second.value();
  while (indexes[it] != nullopt) {
    sub.push_front(array[indexes[it].value()]);
    it = indexes[it].value();
  }
  return {
      {0},                       // Sum of sequence.
      {sub.begin(), sub.end()},  // Elements of the sequence.
  };
}

int main() {
  vector<int> arr{10, 70, 20, 30, 50, 11, 30};
  vector<vector<int>> result = maxSumIncreasingSubsequence(arr);

  // Expected sum and subsequence
  int expected_sum = 110;
  vector<int> expected_subseq{10, 20, 30, 50};

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
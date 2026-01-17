#include <functional>
#include <set>
#include <vector>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  if (array.size() == 0)
    return {};

  int startRow = 0;
  int endRow = array.size() - 1;
  int startCol = 0;
  int endCol = array[0].size() - 1;

  vector<int> res = {};

  while (startRow <= endRow && startCol <= endCol) {
    for (int i = startCol; i <= endCol; ++i) {
      res.push_back(array[startRow][i]);
    }
    for (int i = startRow + 1; i <= endRow; ++i) {
      res.push_back(array[i][endCol]);
    }
    for (int i = endCol - 1; i >= startCol; --i) {
      if (startRow == endRow)
        break;
      res.push_back(array[endRow][i]);
    }
    for (int i = endRow - 1; i >= startRow; --i) {
      if (startCol == endCol)
        break;
      res.push_back(array[i][startCol]);
    }
    startRow++;
    endRow--;
    startCol++;
    endCol--;
  }
  return res;
};

int lengthOfLongestSubstring(string s) {
  if (s.size() == 0)
    return 0;
  int left = 0;
  set<char> window;
  int max_length = 0;
  for (int right = 0; right < s.size(); right++) {
    while (window.find(s[right]) != window.end()) {
      window.erase(s[right]);
      left++;
    }
    window.insert(s[right]);
    max_length = max(max_length, right - left + 1);
  }
  return max_length;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
  if (array.size() == 1) {
    return array[0];
  }
  vector<int> res;
  if (array[0].size() == 1) {
    for (auto &item : array) {
      res.push_back(item[0]);
    }
    return res;
  }

  int row = 0;
  int col = 0;

  enum Direction { DOWN, UP };
  Direction direction{DOWN};

  auto is_perimeter = [&]() -> bool {
    return (row == 0) || (row == array.size() - 1) || (col == 0) ||
           (col == array[0].size() - 1);
  };
  while (res.size() != array.size() * array[0].size()) {
    res.push_back(array[row][col]);
    if (!is_perimeter()) {
      row = direction == DOWN ? ++row : --row;
      col = direction == DOWN ? --col : ++col;
      continue;
    }

    if (col == 0 && direction == DOWN) {
      if (row == array.size() - 1) {
        col++;
      } else {
        ++row;
      }
      direction = UP;
      continue;
    }
    if (col == 0 && direction == UP) {
      --row;
      ++col;
      continue;
    }
    if (col == array[0].size() - 1 && direction == DOWN) {
      ++row;
      --col;
      continue;
    }
    if (col == array[0].size() - 1 && direction == UP) {
      ++row;
      direction = DOWN;
      continue;
    }
    if (row == 0 && direction == DOWN) {
      ++row;
      --col;
      continue;
    }
    if (row == 0 && direction == UP) {
      if (col == array[0].size() - 1) {
        ++row;
      } else {
        ++col;
      }
      direction = DOWN;
      continue;
    }
    if (row == array.size() - 1 && direction == DOWN) {
      ++col;
      direction = UP;
      continue;
    }
    if (row == array.size() - 1 && direction == UP) {
      ++col;
      --row;
      continue;
    }
  }
  return res;
}

vector<int> longestSubarrayWithSum(vector<int> array, int targetSum) {
  int left = 0, right = 0;
  vector<int> out{};
  int curr = array[0];
  int largest = 0;
  while (right < array.size()) {
    if (targetSum - curr == 0) {
      if (right - left + 1 > largest) {
        out = {left, right};
        largest = right - left + 1;
      }
      right++;
      if (right < array.size())
        curr += array[right];
      continue;
    }
    if (targetSum - curr < 0) {
      curr -= array[left];
      left++;
      continue;
    }
    if (targetSum - curr > 0) {
      right++;
      curr += array[right];
    }
  }
  return out;
}

auto isPeak(int left, int mid, int right) {
  if (mid > left && mid > right) {
    return true;
  }
  return false;
}

int longestPeak(vector<int> array) {
  if (array.size() < 3) {
    return 0;
  }
  vector<int> peaks{};
  int ptr{1};
  while (ptr < array.size() - 1) {
    int left = array[ptr - 1];
    int mid = array[ptr];
    int right = array[ptr + 1];
    if (isPeak(left, mid, right)) {
      peaks.push_back(ptr);
    }
    ptr++;
  }
  int max_length{0};
  int curr_max{3};
  for (auto &index : peaks) {
    int left = index - 1;
    int right = index + 1;
    while (left - 1 >= 0) {
      if (array[left - 1] < array[left]) {
        --left;
        curr_max++;
      } else {
        break;
      }
    }

    while (right + 1 < array.size()) {
      if (array[right + 1] < array[right]) {
        right++;
        curr_max++;
      } else {
        break;
      }
    }
    if (curr_max > max_length) {
      max_length = curr_max;
    }
    curr_max = 3;
  }
  return max_length;
}

vector<int> arrayOfProducts(vector<int> array) {
  int size = array.size();
  vector<int> left(size, 1);
  vector<int> right(size, 1);
  int product = array[0];
  for (int i = 1; i < size; i++) {
    left[i] = product;
    product *= array[i];
  }
  product = array[size];
  for (int i = size - 2; i >= 0; --i) {
    right[i] = product;
    product *= array[i];
  }
  for (int i = 0; i < size; ++i) {
    left[i] *= right[i];
  }
  return left;
}

int main() {
  vector<int> prod = arrayOfProducts({5, 1, 4, 2});
  int lpeak = longestPeak({1, 2, 3, 4, 5, 1});
  vector<int> lsws = longestSubarrayWithSum({0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10);

  vector<int> out = zigzagTraverse({
      {1, 3, 4, 10},
      {2, 5, 9, 11},
      {6, 8, 12, 15},
      {7, 13, 14, 16},
  });
  vector<int> res = spiralTraverse({
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  });
  lengthOfLongestSubstring("pwwkew");
  return 0;
}

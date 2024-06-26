// You're given an array of integers and an integer. Write a function that moves
// all instances of that integer in the array to the end of the array and
// returns the array.
// The function should perform this in place (i.e., it should mutate the input
// array) and doesn't need to maintain the order of the other integers.

// Sample Input
// array  = [2, 1, 2, 2, 2, 3, 4, 2]
// toMove = 2

// Sample Output
// [1, 3, 4, 2, 2, 2, 2, 2] - the numbers 1, 3, and 4 could be ordered
// differently

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int i = 0;
  int j = array.size() - 1;
  while (i < j) {
    while (i < j && array[j] == toMove) {
      j--;
    }
    if (array[i] == toMove) {
      swap(array[i], array[j]);
    }
    i++;
  }
  return array;
}

TEST(My, Test1) {
  vector input{2, 1, 2, 2, 2, 3, 4, 2};
  vector res{4, 1, 3, 2, 2, 2, 2, 2};
  EXPECT_EQ(res, moveElementToEnd(input, 2));
}

TEST(My, Test2) {
  vector<int> input{};
  vector<int> res{};
  EXPECT_EQ(res, moveElementToEnd(input, 3));
}

TEST(My, Test3) {
  vector<int> input{1, 2, 4, 5, 6};
  vector<int> res{1, 2, 4, 5, 6};
  EXPECT_EQ(res, moveElementToEnd(input, 3));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

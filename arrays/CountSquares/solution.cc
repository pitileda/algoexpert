#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int countSquares(vector<vector<int>> points) {
  int count{0};
  unordered_set<vector<int>> points_set(points.begin(), points.end());
  for (int i = 0; i < points.size(); i++) {
    for (int j = 0; j < points.size(); j++) {
      if (i == j) continue;
      int p1x = points[i][0];
      int p2x = points[j][0];
      int p1y = points[i][1];
      int p2y = points[j][1];
      // find mid point
      int midx = max(p1x, p2x) - (max(p1x, p2x) - min(p1x, p2x)) / 2;
      int midy = max(p1y, p2y) - (max(p1y, p2y) - min(p1y, p2y)) / 2;

      int dx = p1x - midx;
      int dy = p1y - midy;

      int pot1x = midx + dy;
      int pot1y = midy + dx;
      int pot2x = midx - dy;
      int pot2y = midy - dx;

      if (points_set.find({pot1x, pot1y}) != points_set.end() &&
          points_set.find({pot2x, pot2y}) != points_set.end()) {
        count++;
      }
    }
  }
  return count / 4;
}

int main(int argc, char *argv[]) {
  return countSquares(
      {{1, 1}, {0, 0}, {-4, 2}, {-2, -1}, {0, 1}, {1, 0}, {-1, 4}});
}

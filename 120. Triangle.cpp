#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    return minimumTotal(triangle, 0, 0);
  }

  int minimumTotal(vector<vector<int>> &triangle, int row, int col) {
    if (row == triangle.size() - 1)
      return triangle[row][col];
    return min(minimumTotal(triangle, row + 1, col),
               minimumTotal(triangle, row + 1, col + 1)) +
           triangle[row][col];
  }
};

int main() {
  vector<vector<int>> v{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int r = Solution().minimumTotal(v);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  // 12ms
  int minPathSum(vector<vector<int>> &grid) {
    for (int col = 1; col < grid[0].size(); col++)
      grid[0][col] += grid[0][col - 1];
    for (int i = 1; i < grid.size(); i++) {
      grid[i][0] += grid[i - 1][0];
      for (int j = 1; j < grid[0].size(); j++)
        grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
    }
    return grid.back().back();
  }
  // 4ms
  int minPathSum2(vector<vector<int>> &grid) {
    vector<int> &v = grid[0];
    for (int col = 1; col < v.size(); col++)
      v[col] += v[col - 1];
    for (int i = 1; i < grid.size(); i++) {
      v[0] += grid[i][0];
      for (int j = 1; j < v.size(); j++)
        v[j] = min(v[j - 1], v[j]) + grid[i][j];
    }
    return v.back();
  }
};

int main() {
  vector<vector<int>> v{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int r = Solution().minPathSum(v);
  return 0;
}
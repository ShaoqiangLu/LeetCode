#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid[0][0])
      return 0;
    vector<int> v(obstacleGrid[0]);
    for (int &n : v)
      n = n == 0;
    for (int i = 1; i < obstacleGrid.size(); i++) {
      if (obstacleGrid[i][0])
        v[0] = 0;
      for (int j = 1; j < v.size(); j++)
        v[j] = obstacleGrid[i][j] ? 0 : v[j] + v[j - 1];
    }
    return v.back();
  }
};

int main() {
  vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int r = Solution().uniquePathsWithObstacles(v);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    vector<long> v(obstacleGrid[0].size() + 1);
    if (!obstacleGrid[0][0])
      v[1] = 1;
    for (int i = 0; i < obstacleGrid.size(); i++)
      for (int j = 0; j < v.size() - 1; j++)
        v[j + 1] = obstacleGrid[i][j] ? 0 : v[j + 1] + v[j];
    return v.back();
  }
};

int main() {
  vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int r = Solution().uniquePathsWithObstacles(v);
  return 0;
}
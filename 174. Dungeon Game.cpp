#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<int> v(n + 1, INT_MAX);
    v[n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--) {
        int need = min(v[j], v[j + 1]) - dungeon[i][j];
        v[j] = need <= 0 ? 1 : need;
      }
    return v[0];
  }
};

int main() {
  vector<vector<int>> v{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
  int r = Solution().calculateMinimumHP(v);
  return 0;
}
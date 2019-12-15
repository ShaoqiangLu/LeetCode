#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int idx_down = -1, idx_up = -1, id;
    for (int i = 0; i < n - 1; i++) {
      if (height[i] > height[i + 1] && idx_down < 0)
        idx_down = i;
      if (height[i] < height[i + 1] && idx_up < 0)
        idx_up = i;
      if (height[i] >= height[i + 1] && idx_down >= 0)
        idx_down = i;
    }
  }
};

int main() {
  vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto r = Solution().trap(v);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int pos = nums.size() - 1;
    for (int i = pos - 1; i >= 0; i--)
      if (i + nums[i] >= pos)
        pos = i;
    return pos == 0;
  }
  // DP(timeout)
  bool canJump2(vector<int> &nums) {
    if (nums.size() == 1)
      return true;
    vector<bool> v(nums.size());
    v[0] = nums[0];
    for (int i = 0; i < nums.size() && v[i]; i++) {
      for (int j = nums[i]; j >= 1; j--) {
        if (i + j >= nums.size() - 1)
          return true;
        v[i + j] = true;
      }
    }
    return false;
  }
};

int main() {
  vector<int> v{2, 3, 1, 1, 4};
  bool r = Solution().canJump(v);
  return 0;
}
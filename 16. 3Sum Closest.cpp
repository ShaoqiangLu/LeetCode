#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int close = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int val = nums[i] + nums[j] + nums[k];
        if (abs(target - close) > abs(target - val))
          close = val;
        if (val < target)
          j++;
        else
          k--;
      }
    }
    return close;
  }
};

int main() {
  vector<int> v{-1, 2, 1, -4};
  int r = Solution().threeSumClosest(v, 1);
  return 0;
}
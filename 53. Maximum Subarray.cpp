#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_so_far = INT_MIN, max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      max_so_far = (max_so_far > 0 ? max_so_far : 0) + nums[i];
      if (max_so_far > max)
        max = max_so_far;
    }
    return max;
  }
};

int main() {
  vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int r = Solution().maxSubArray(v);
  return 0;
}
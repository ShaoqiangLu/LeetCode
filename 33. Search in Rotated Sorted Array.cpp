#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
      int mid = (hi - lo) / 2 + lo;
      if (nums[mid] > nums[hi])
        lo = mid + 1;
      else
        hi = mid;
    }
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l, realMid = (mid + lo) % nums.size();
      if (nums[realMid] == target)
        return realMid;
      else if (nums[realMid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return -1;
  }
};

int main() {
  vector<int> v{4, 5, 6, 7, 0, 1, 2};
  int r = Solution().search(v, 0);
  return 0;
}
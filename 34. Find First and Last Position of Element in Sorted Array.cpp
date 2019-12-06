#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int mid = binarySearch(nums, 0, nums.size() - 1, target);
    if (mid != -1) {
      int l = mid, r = mid;
      vector<int> res(2);
      while (l != -1) {
        res[0] = l;
        l = binarySearch(nums, 0, l - 1, target);
      }
      while (r != -1) {
        res[1] = r;
        r = binarySearch(nums, r + 1, nums.size() - 1, target);
      }
      return res;
    } else
      return {-1, -1};
  }

private:
  int binarySearch(vector<int> nums, int lo, int hi, int target) {
    while (lo <= hi) {
      int mid = (hi - lo) / 2 + lo;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return -1;
  }
};

int main() {
  vector<int> v{2, 2};
  vector<int> r = Solution().searchRange(v, 2);
  return 0;
}
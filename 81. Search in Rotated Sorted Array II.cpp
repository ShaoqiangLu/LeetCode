#include <vector>

using namespace std;

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    if (nums.empty())
      return false;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (r - l) / 2 + l;
      if (nums[mid] < nums[r])
        r = mid;
      else if (nums[mid] > nums[r])
        l = mid + 1;
      else if (nums[r - 1] <= nums[r])
        r--;
      else {
        l = r;
      }
    }
    if (target > nums.back()) {
      l = 0;
      r = r - 1;
    } else if (target < nums.back())
      r = nums.size() - 1;
    else
      return true;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (nums[mid] == target)
        return true;
      else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return false;
  }
};

int main() {
  vector<int> v{};
  auto r = Solution().search(v, 0);
  return 0;
}
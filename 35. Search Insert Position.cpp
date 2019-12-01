#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left;
  }
};

int main() {
  vector<int> nums{1, 3, 5};
  int r = Solution().searchInsert(nums, 4);
  return 0;
}
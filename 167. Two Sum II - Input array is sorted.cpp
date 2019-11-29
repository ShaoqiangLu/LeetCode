#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0, j = nums.size() - 1; i < j;) {
      int sum = nums[i] + nums[j];
      if (sum < target)
        i++;
      else if (sum > target)
        j--;
      else
        return {i + 1, j + 1};
    }
    return {};
  }
};

int main() {
  vector<int> nums{2, 7, 11, 15};
  int target = 9;
  vector<int> result = Solution().twoSum(nums, target);
  return 0;
}
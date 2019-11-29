#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size();) {
      for (size_t j = i + 1; j < nums.size();) {
        search(nums, i, j, target - nums[i] - nums[j], result);
        do
          j++;
        while (j < nums.size() && nums[j - 1] == nums[j]);
      }
      do
        i++;
      while (i < nums.size() && nums[i - 1] == nums[i]);
    }
    return result;
  }

  void search(vector<int> &nums, size_t i, size_t j, int target,
              vector<vector<int>> &result) {
    for (size_t left = j + 1, right = nums.size() - 1; left < right;) {
      int val = nums[left] + nums[right];
      if (val > target)
        right--;
      else if (val < target)
        left++;
      else {
        result.push_back({nums[i], nums[j], nums[left], nums[right]});
        do
          left++;
        while (left < right && nums[left - 1] == nums[left]);
        do
          right--;
        while (left < right && nums[right] == nums[right + 1]);
      }
    }
  }
};

int main() {
  vector<int> nums{1, 0, -1, 0, -2, 2};
  vector<vector<int>> result = Solution().fourSum(nums, 0);
  return 0;
}
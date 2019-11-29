#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size();) {
      if (nums[i] > 0)
        break;
      int target = -nums[i];
      for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
        if (nums[k] < 0)
          break;
        int val = nums[j] + nums[k];
        if (val > target)
          k--;
        else if (val < target)
          j++;
        else {
          result.push_back({nums[i], nums[j], nums[k]});
          int left = nums[j];
          int right = nums[k];
          while ((j < k) && (nums[j] == left))
            j++;
          while ((j < k) && (nums[k] == right))
            k--;
        }
      }
      while ((i < nums.size()) && (nums[i] == -target))
        i++;
    }
    return result;
  }
};

int main() {
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = Solution().threeSum(nums);
  return 0;
}
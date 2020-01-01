#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<int> tmp;
    vector<vector<int>> res;
    permute(nums, 0, res);
    return res;
  }

  void permute(vector<int> &nums, int idx, vector<vector<int>> &res) {
    int n = nums.size();
    if (idx == nums.size())
      res.push_back(nums);
    for (int i = idx; i < n; i++) {
      if (nums[idx] != nums[i]) {
        swap(nums[idx], nums[i]);
        permute(nums, idx + 1, res);
        swap(nums[idx], nums[i]);
      }
    }
  }
};

int main() {
  vector<int> v{1, 1, 3};
  auto r = Solution().permuteUnique(v);
  return 0;
}
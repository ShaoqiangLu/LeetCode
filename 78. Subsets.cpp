#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    subsets(nums, res, tmp, 0);
    return res;
  }
  // Recursive
  void subsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp,
               int idx) {
    if (idx == nums.size()) {
      res.push_back(tmp);
      return;
    }
    subsets(nums, res, tmp, idx + 1);
    tmp.push_back(nums[idx]);
    subsets(nums, res, tmp, idx + 1);
    tmp.pop_back();
  }
  // Iterative
  vector<vector<int>> subsets_iterative(vector<int> &nums) {
    vector<vector<int>> res{{}};
    for (int i = 0; i < nums.size(); i++) {
      int n = res.size();
      for (int j = 0; j < n; j++) {
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
  // bit manipulation
  vector<vector<int>> subsets_bit(vector<int> &nums) {
    int n = 1 << nums.size();
    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < nums.size() && i >> j > 0; j++)
        if (i >> j & 1)
          res[i].push_back(nums[j]);
    return res;
  }
};

int main() {
  vector<int> v{1, 2, 3};
  auto r = Solution().subsets_bit(v);
  return 0;
}
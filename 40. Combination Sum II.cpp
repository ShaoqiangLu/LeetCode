#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, 0, target, res, tmp);
    return res;
  }

  void combinationSum(vector<int> &candidates, int start, int target,
                      vector<vector<int>> &res, vector<int> &tmp) {
    if (target == 0) {
      res.push_back(tmp);
      return;
    }
    for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
      if (i > start && candidates[i - 1] == candidates[i])
        continue;
      tmp.push_back(candidates[i]);
      combinationSum(candidates, i + 1, target - candidates[i], res, tmp);
      tmp.pop_back();
    }
  }
};

int main() {
  vector<int> v{10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> r = Solution().combinationSum2(v, 8);
  return 0;
}
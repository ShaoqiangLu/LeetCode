#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    combinationSum(candidates, 0, target, res, tmp);
    return res;
  }

  void combinationSum(vector<int> &candidates, int start, int target,
                      vector<vector<int>> &res, vector<int> &tmp) {
    if (target == 0) {
      res.push_back(tmp);
      return;
    } else if (target < 0)
      return;
    for (int i = start; i < candidates.size(); i++) {
      tmp.push_back(candidates[i]);
      combinationSum(candidates, i, target - candidates[i], res, tmp);
      tmp.pop_back();
    }
  }
};

int main() {
  vector<int> v{8, 7, 4, 3};
  vector<vector<int>> r = Solution().combinationSum(v, 11);
  return 0;
}
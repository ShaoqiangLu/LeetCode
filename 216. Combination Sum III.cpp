#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> tmp;
    combinationSum(k, 1, n, res, tmp);
    return res;
  }

  void combinationSum(int k, int start, int n, vector<vector<int>> &res,
                      vector<int> &tmp) {
    if (n == 0 && k == 0) {
      res.push_back(tmp);
      return;
    }
    for (int i = start; i < 10 && n >= i; i++) {
      tmp.push_back(i);
      combinationSum(k - 1, i + 1, n - i, res, tmp);
      tmp.pop_back();
    }
  }
};

int main() {
  vector<vector<int>> r = Solution().combinationSum3(3, 7);
  return 0;
}
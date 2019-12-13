#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp(k);
    combine(1, 0, n, k, res, tmp);
    return res;
  }

  void combine(int start, int len, int n, int k, vector<vector<int>> &res,
               vector<int> &tmp) {
    if (len == k) {
      res.push_back(tmp);
      return;
    }
    for (int i = start; i < n + 1; i++) {
      tmp[len] = i;
      combine(i + 1, len + 1, n, k, res, tmp);
    }
  }
};

int main() {
  vector<vector<int>> r = Solution().combine(4, 2);
  return 0;
}
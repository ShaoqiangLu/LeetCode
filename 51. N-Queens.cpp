#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> tmp(n, string(n, '.'));
    solveNQueens(n, 0, res, tmp);
    return res;
  }

  void solveNQueens(int n, int row, vector<vector<string>> &res,
                    vector<string> &tmp) {
    if (row == n) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (is_valid(n, row, i, tmp)) {
        tmp[row][i] = 'Q';
        solveNQueens(n, row + 1, res, tmp);
        tmp[row][i] = '.';
      }
    }
  }

  bool is_valid(int n, int row, int col, vector<string> &tmp) {
    for (int i = 0; i < n; i++)
      if (tmp[i][col] == 'Q')
        return false;
    for (int i = max(-row, -col); i <= -1; i++)
      if (tmp[row + i][col + i] == 'Q')
        return false;
    for (int i = max(-row, col - n + 1); i <= -1; i++)
      if (tmp[row + i][col - i] == 'Q')
        return false;
    return true;
  }
};

int main() {
  auto r = Solution().solveNQueens(4);
  return 0;
}
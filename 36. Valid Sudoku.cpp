#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';
          if (used1[i][num] || used2[j][num] || used3[i / 3 * 3 + j / 3][num])
            return false;
          used1[i][num] = used2[j][num] = used3[i / 3 * 3 + j / 3][num] = true;
        }
      }
    return true;
  }
};

int main() {
  vector<vector<char>> v;
  bool r = Solution().isValidSudoku(v);
  return 0;
}
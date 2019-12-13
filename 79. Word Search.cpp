#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int idx = 0;
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          char c = board[i][j];
          board[i][j] = 0;
          if (exist(i, j, board, word, idx + 1))
            return true;
          board[i][j] = c;
        }
      }
    return false;
  }

  bool exist(int i, int j, vector<vector<char>> &board, string &word, int idx) {
    if (idx == word.size())
      return true;
    for (int k = 0; k < 4; k++) {
      int row = i + a[k][0], col = j + a[k][1];
      if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        continue;
      if (board[row][col] == word[idx]) {
        char c = board[row][col];
        board[row][col] = 0;
        if (exist(row, col, board, word, idx + 1))
          return true;
        board[row][col] = c;
      }
    }
    return false;
  }

private:
  int a[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
};

int main() {
  vector<vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  bool r = Solution().exist(board, "ABCB");
  return 0;
}
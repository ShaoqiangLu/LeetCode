#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0)
      return {};
    int i = 0, j = 0, state = 0, row_start = 0, row_end = matrix.size() - 1,
        col_start = 0, col_end = matrix[0].size() - 1;
    vector<int> res;
    while (row_start <= row_end && col_start <= col_end) {
      res.push_back(matrix[i][j]);
      switch (state) {
      case 0:
        if (j == col_end) {
          state = 1;
          row_start++;
          i++;
        } else
          j++;
        break;
      case 1:
        if (i == row_end) {
          state = 2;
          col_end--;
          j--;
        } else
          i++;
        break;
      case 2:
        if (j == col_start) {
          state = 3;
          row_end--;
          i--;
        } else
          j--;
        break;
      case 3:
        if (i == row_start) {
          state = 0;
          col_start++;
          j++;
        } else
          i--;
        break;
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> r = Solution().spiralOrder(v);
  return 0;
}
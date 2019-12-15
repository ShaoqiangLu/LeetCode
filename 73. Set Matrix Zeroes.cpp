#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    bool first_row = false, first_col = false;
    for (int row = 0; row < matrix.size(); row++)
      if (matrix[row][0] == 0) {
        first_col = true;
        break;
      }
    for (int col = 0; col < matrix[0].size(); col++)
      if (matrix[0][col] == 0) {
        first_row = true;
        break;
      }
    for (int i = 1; i < matrix.size(); i++)
      for (int j = 1; j < matrix[0].size(); j++)
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
    for (int row = 1; row < matrix.size(); row++)
      if (matrix[row][0] == 0)
        for (int col = 1; col < matrix[0].size(); col++)
          matrix[row][col] = 0;
    for (int col = 1; col < matrix[0].size(); col++)
      if (matrix[0][col] == 0)
        for (int row = 1; row < matrix.size(); row++)
          matrix[row][col] = 0;
    if (first_row)
      for (int col = 0; col < matrix[0].size(); col++)
        matrix[0][col] = 0;
    if (first_col)
      for (int row = 0; row < matrix.size(); row++)
        matrix[row][0] = 0;
  }
};

int main() {
  vector<vector<int>> v{{0, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  Solution().setZeroes(v);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  // time O(n+m)
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int i = 0, j = matrix[0].size() - 1;
    int m = matrix.size - 1;
    while (i <= m && j >= 0)
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] < target)
        i++;
      else
        j--;
    return false;
  }

  // time O(nlogn)
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int row = matrix.size() - 1, col = matrix[0].size() - 1;
    for (int i = 0; i <= row && i <= col; i++) {
      int l = i, r = row;
      while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (matrix[mid][i] == target)
          return true;
        else if (matrix[mid][i] < target)
          l = mid + 1;
        else
          r = mid - 1;
      }
      row = l - 1;
      if (row < 0)
        return false;
      l = i, r = col;
      while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (matrix[i][mid] == target)
          return true;
        else if (matrix[i][mid] < target)
          l = mid + 1;
        else
          r = mid - 1;
      }
      col = l - 1;
      if (col < 0)
        return false;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> v{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  bool r = Solution().searchMatrix(v, 3);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int l = 0, r = matrix.size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (matrix[mid][0] == target)
        return true;
      else if (matrix[mid][0] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    int row = l - 1;
    if (row < 0)
      return false;
    l = 0, r = matrix[0].size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (matrix[row][mid] == target)
        return true;
      else if (matrix[row][mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> v{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  bool r = Solution().searchMatrix(v, 3);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  // math:C(m+n-2,m-1) O(n)
  int uniquePaths(int m, int n) {
    long res = 1;
    for (int i = 1; i < n; i++) {
      res = res * (m + i - 1) / i;
    }
    return res;
  }

  // DP O(m*n)
  int DP(int m, int n) {
    vector<int> v(n, 1);
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        v[j] += v[j - 1];
    return v[n - 1];
    swap(v, v);
  }

  // DFS(timeout)
  void DFS(int m, int n) {
    if (m == 1 || n == 1)
      count++;
    else {
      DFS(m - 1, n);
      DFS(m, n - 1);
    }
  }

private:
  int count;
};

int main() {
  int r = Solution().DP(3, 3);
  return 0;
}
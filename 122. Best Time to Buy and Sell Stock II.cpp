#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int res = 0, n = prices.size();
    for (int i = 0; i < n - 1; i++) {
      if (prices[i + 1] - prices[i] > 0)
        res += prices[i + 1] - prices[i];
    }
    return res;
  }
};

int main() {
  vector<int> v{7, 1, 5, 3, 6, 4};
  int r = Solution().maxProfit(v);
  return 0;
}
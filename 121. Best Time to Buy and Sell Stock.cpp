#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min_so_far = INT_MAX, max = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (min_so_far > prices[i])
        min_so_far = prices[i];
      else if (max < prices[i] - min_so_far)
        max = prices[i] - min_so_far;
    }
    return max;
  }
};

int main() {
  vector<int> v{7, 1, 5, 3, 6, 4};
  int r = Solution().maxProfit(v);
  return 0;
}
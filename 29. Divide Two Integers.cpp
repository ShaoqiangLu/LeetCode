#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN)
      if (divisor == 1)
        return INT_MIN;
      else if (divisor == -1)
        return INT_MAX;
    int sign = 1, flag = 0;
    if (dividend == INT_MIN && divisor == INT_MIN)
      return 1;
    else if (divisor == INT_MIN)
      return 0;
    else if (dividend == INT_MIN) {
      dividend += 1;
      flag = 1;
    }
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
      sign = -1;
    dividend = abs(dividend);
    divisor = abs(divisor);

    int res = 0;
    while (dividend) {
      int tmp = divisor, count = 1;
      while (dividend / tmp) {
        tmp <<= 1;
        count <<= 1;
      }
      tmp >>= 1;
      count >>= 1;
      res += count;
      dividend %= tmp;
    }
    return res;
  }
};

int main() {
  int r = Solution().divide(-10, 3);
  return 0;
}
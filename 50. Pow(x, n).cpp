#include <climits>

class Solution {
public:
  double myPow(double x, int n) {
    double res = 1;
    int sign = 1;
    if (n == 0)
      return 1;
    else if (n < 0) {
      sign = -1;
    }
    while (n != 1 && n != -1) {
      if (n % 2)
        res *= x;
      x *= x;
      n /= 2;
    }
    return sign == -1 ? 1 / x / res : res * x;
  }
};

int main() {
  double r = Solution().myPow(-2, -11);
  return 0;
}
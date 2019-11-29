#include <climits>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int r = 0;
    while (x != 0) {
      int pop = x % 10;
      if (r > INT_MAX / 10 || (r == INT_MAX / 10 && pop > 7))
        return 0;
      if (r < INT_MIN / 10 || (r == INT_MIN / 10 && pop < -8))
        return 0;
      r = r * 10 + pop;
      x /= 10;
    }
    return r;
  }
};

int main() {
  int r = Solution().reverse(-123);
  return 0;
}
#include <cstdint>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int r = 0;
    while (n) {
      n &= (n - 1);
      r++;
    }
    return r;
  }
};

int main() {
  int r = Solution().hammingWeight(0b00000000000000000000000000001011);
  return 0;
}
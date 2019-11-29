#include <cstdint>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;
    for (size_t i = 0; i < 32; i++)
      r = (r << 1) + (n >> i & 1);
    return r;
  }
};

int main() {
  uint32_t r = Solution().reverseBits(0b00000010100101000001111010011100);
  return 0;
}
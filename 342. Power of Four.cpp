class Solution {
public:
  bool isPowerOfFour(int n) {
    return n > 0 && !(n & n - 1) && (n & 0x55555555);
  }
};

int main() {
  bool r = Solution().isPowerOfFour(16);
  return 0;
}
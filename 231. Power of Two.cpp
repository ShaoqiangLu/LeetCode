class Solution {
public:
  bool isPowerOfTwo(int n) { return n > 0 && ((n & n - 1) == 0); }
};

int main() {
  bool r = Solution().isPowerOfTwo(8);
  return 0;
}
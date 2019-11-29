class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0; // 3^19
  }
};

int main() {
  bool r = Solution().isPowerOfThree(9);
  return 0;
}
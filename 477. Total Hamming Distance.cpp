class Solution {
public:
  int hammingDistance(int x, int y) {
    int count = 0, n = x ^ y;
    while (n) {
      n &= n - 1;
      count++;
    }
    return count;
  }
};

int main() {
  int r = Solution().hammingDistance(8, 9);
  return 0;
}
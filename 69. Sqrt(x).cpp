class Solution {
public:
  int mySqrt(int x) {
    int l = 1, r = x, mid;
    while (l <= r) {
      mid = (r - l) / 2 + l;
      if (mid <= x / mid)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l - 1;
  }
};

int main() {
  // 3 solutions:Newton,BS,loop
  int r = Solution().mySqrt(8);
  return 0;
}
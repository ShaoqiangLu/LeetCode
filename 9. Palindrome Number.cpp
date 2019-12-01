class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || x % 10 == 0 && x)
      return false;
    int rev = 0;
    while (x > rev) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    return x == rev || x == rev / 10;
  }
};

int main() {
  bool r = Solution().isPalindrome(10);
  return 0;
}
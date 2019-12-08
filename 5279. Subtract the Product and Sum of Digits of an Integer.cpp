class Solution {
public:
  int subtractProductAndSum(int n) {
    int rest, product = 1, sum = 0;
    while (n) {
      rest = n % 10;
      product *= rest;
      sum += rest;
      n /= 10;
    }
    return product - sum;
  }
};

int main() {
  int r = Solution().subtractProductAndSum(234);
  return 0;
}
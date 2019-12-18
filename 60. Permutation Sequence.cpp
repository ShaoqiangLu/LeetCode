#include <string>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) { getPermutation(n - 1, k / n) }
};

int main() {
  auto r = Solution().getPermutation(3, 3);
  return 0;
}
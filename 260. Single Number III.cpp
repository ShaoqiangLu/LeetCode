#include <vector>

using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    vector<int> r(2);
    int c = 0;
    for (int n : nums)
      c ^= n;
    c &= -c;
    for (int n : nums)
      if (n & c)
        r[0] ^= n;
      else {
        r[1] ^= n;
      }
    return r;
  }
};

int main() {
  vector<int> v{8, 9, 8};
  vector<int> r = Solution().singleNumber(v);
  return 0;
}
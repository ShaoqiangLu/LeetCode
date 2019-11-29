#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> r(num + 1);
    for (int i = 1; i <= num; i++) {
      r[i] = r[i & i - 1] + 1;
    }
    return r;
  }
};

int main() {
  vector<int> r = Solution().countBits(8);
  return 0;
}
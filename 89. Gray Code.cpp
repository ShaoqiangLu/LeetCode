#include <vector>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> res{0};
    for (int i = 0; i < n; i++) {
      int t = res.back(), count = 0;
      while (t) {
        count++;
        t >>= 1;
      }
      for (int j = res.size() - 1; j >= 0; j--) {
        res.push_back(res[j] + (1 << count));
      }
    }
    return res;
  }
};

int main() {
  vector<int> r = Solution().grayCode(2);
  return 0;
}
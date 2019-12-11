#include <string>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0;
    while () {
      if (p[j] == '*') {
        i = s.size() - 1;
        j = p.size() - 1;
      }
      if (s[i] == p[j]) {
        i++;
        j++;
      }
    }
  }
};

int main() {
  bool r = Solution().isMatch("afgsgb", "a*b");
  return 0;
}
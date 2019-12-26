#include <string>

using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    int state = 0;
    for (int idx1 = 0, idx2 = s.size() - 1; idx1 < idx2;) {
      if (s[idx1] != s[idx2])
        switch (state) {
        case 0:
          idx1++;
          state++;
          break;
        case 1:
          idx1--;
          idx2--;
          state++;
          break;
        case 2:
          return false;
          break;
        }
      else {
        idx1++;
        idx2--;
      }
    }
    return true;
  }
};

int main() {
  auto r = Solution().validPalindrome("abca");
  return 0;
}
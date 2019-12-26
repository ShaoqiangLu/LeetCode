#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    for (int idx1 = 0, idx2 = s.size() - 1; idx1 < idx2; idx1++, idx2--) {
      while (idx1 < idx2 && !isalnum(s[idx1]))
        idx1++;
      while (idx1 < idx2 && !isalnum(s[idx2]))
        idx2--;
      if (tolower(s[idx1]) != tolower(s[idx2]))
        return false;
    }
    return true;
  }
};

int main() {
  auto r = Solution().isPalindrome("0P");
  return 0;
}
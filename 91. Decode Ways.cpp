#include <string>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int pre = 0, cur = 1, next = 0;
    char pre_char = '0';
    for (char c : s) {
      next = (c != '0') * cur +
             (pre_char == '1' || (pre_char == '2' && c <= '6')) * pre;
      pre = cur;
      cur = next;
      pre_char = c;
    }
    return cur;
  }
  // DFS(timeout)
  void helper(string s) {
    if (s.size() == 1)
      count += s == "0" ? 0 : 1;
    else if (s.size() == 2) {
      if (s.substr(0, 2) <= "26" && s.substr(0, 2) >= "10")
        count++;
      if (s[0] != '0')
        helper(s.substr(1, s.size() - 1));
    } else {
      if (s.substr(0, 2) <= "26" && s.substr(0, 2) >= "10")
        helper(s.substr(2, s.size() - 2));
      if (s[0] != '0')
        helper(s.substr(1, s.size() - 1));
    }
  }

private:
  int count = 0;
};

int main() {
  int r = Solution().numDecodings("12");
  return 0;
}
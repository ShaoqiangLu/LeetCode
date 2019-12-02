#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int res = 0, tail = s.size() - 1;
    while (tail >= 0 && s[tail] == ' ')
      tail--;
    while (tail >= 0 && s[tail--] != ' ')
      res++;
    return res;
  }
};

int main() {
  int r = Solution().lengthOfLastWord("Hello World");
  return 0;
}
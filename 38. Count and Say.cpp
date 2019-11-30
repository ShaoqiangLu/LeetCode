#include <string>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    for (int i = 1; i < n; i++) {
      string tmp;
      char flag = s[0];
      int count = 0;
      for (auto c : s) {
        if (c == flag)
          count++;
        else {
          tmp.append(to_string(count) + flag);
          flag = c;
          count = 1;
        }
      }
      tmp.append(to_string(count) + flag);
      s = tmp;
    }
    return s;
  }
};

int main() {
  string r = Solution().countAndSay(5);
  return 0;
}
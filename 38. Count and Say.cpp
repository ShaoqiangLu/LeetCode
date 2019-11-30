#include <string>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string res = "1";
    while (--n) {
      string tmp;
      for (size_t i = 0; i < res.size(); i++) {
        int count = 1;
        while (i + 1 < res.size() && res[i] == res[i + 1]) {
          count++;
          i++;
        }
        tmp.append(to_string(count) + res[i]);
      }
      res = tmp;
    }
    return res;
  }
};

int main() {
  string r = Solution().countAndSay(5);
  return 0;
}
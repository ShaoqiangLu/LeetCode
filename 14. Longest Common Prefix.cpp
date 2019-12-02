#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (!strs.size() || !strs[0].size())
      return "";
    bool flag = true;
    int i = 0;
    for (; i < strs.front().size() && flag; i++) {
      for (int j = 1; j < strs.size(); j++)
        if (strs[0][i] != strs[j][i]) {
          flag = false;
          break;
        }
    }
    return strs[0].substr(0, flag ? i : i - 1);
  }
};

int main() {
  vector<string> strs{"flower", "flow", "flight"};
  string r = Solution().longestCommonPrefix(strs);
  return 0;
}
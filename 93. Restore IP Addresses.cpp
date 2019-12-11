#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    restoreIpAddresses(res, s, 0, 0, "");
    return res;
  }

  void restoreIpAddresses(vector<string> &res, string s, int idx, int step,
                          string tmp) {
    int n = s.size();
    if (step == 4) {
      if (idx == n)
        res.push_back(tmp);
      return;
    }
    for (int i = 1; i <= 3; i++)
      if (idx <= n - i && ((i == 2 && s.substr(idx, 2) >= "10") || i != 2) &&
          ((i == 3 && s.substr(idx, 3) <= "255" && s.substr(idx, 3) >= "100") ||
           i != 3))
        restoreIpAddresses(res, s, idx + i, step + 1,
                           tmp + s.substr(idx, i) + (step == 3 ? "" : "."));
  }
};

int main() {
  vector<string> r = Solution().restoreIpAddresses("");
  return 0;
}
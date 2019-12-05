#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    for (int i = 0; i < 3; i++) {
      char add = (digits[0] - '2') * 3 + 'a' + i;
      if (digits.size() > 1) {
        string substr = digits.substr(1, digits.size() - 1);
        vector<string> strs = letterCombinations(substr);
        for (string &str : strs)
          res.push_back(add + str);
      } else {
        res.push_back(string(add));
      }
    }
    return res;
  }
};

int main() {
  vector<string> r = Solution().letterCombinations("23");
  return 0;
}
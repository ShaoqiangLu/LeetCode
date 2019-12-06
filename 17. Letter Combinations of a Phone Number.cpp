#include <string>
#include <vector>

using namespace std;

static vector<vector<string>> v{{"a", "b", "c"}, {"d", "e", "f"},
                                {"g", "h", "i"}, {"j", "k", "l"},
                                {"m", "n", "o"}, {"p", "q", "r", "s"},
                                {"t", "u", "v"}, {"w", "x", "y", "z"}};
class Solution {
public:
  // DFS
  vector<string> letterCombinations1(string digits) {
    if (!digits.size())
      return {};
    vector<string> res;
    for (string s : v[digits[0] - '2']) {
      if (digits.size() > 1) {
        string substr = digits.substr(1, digits.size() - 1);
        vector<string> strs = letterCombinations(substr);
        for (string &str : strs)
          res.push_back(s + str);
      } else {
        string a;
        res.push_back(s);
      }
    }
    return res;
  }
  // BFS
  vector<string> letterCombinations(string digits) {
    if (!digits.size())
      return {};
    vector<string> res{""};
    for (char &c : digits) {
      vector<string> tmp;
      for (string &s : v[c - '2'])
        for (string &str : res)
          tmp.push_back(str + s);
      res = tmp;
    }
    return res;
  }
};

int main() {
  vector<string> r = Solution().letterCombinations("233");
  return 0;
}
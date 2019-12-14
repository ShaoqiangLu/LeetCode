#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> map;
    vector<vector<string>> res;
    for (string &s : strs)
      map[sort(s)].push_back(s);
    for (auto &p : map)
      res.push_back(p.second);
    return res;
  }

  string sort(string s) {
    int counter[26] = {};
    for (char c : s)
      counter[c - 'a']++;
    string res;
    for (int i = 0; i < 26; i++)
      res += string(counter[i], i);
    return res;
  }
};

int main() {
  vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> r = Solution().groupAnagrams(v);
  return 0;
}
#include <list>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // BFS
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int count = 1;
    queue<string> tmp;
    list<string> list(wordList.begin(), wordList.end());
    tmp.push(beginWord);
    while (!tmp.empty()) {
      int n = tmp.size();
      for (int i = 0; i < n; i++) {
        if (tmp.front() == endWord)
          return count;
        for (auto iter = list.begin(); iter != list.end();)
          if (compare(tmp.front(), *iter)) {
            tmp.push(*iter);
            iter = list.erase(iter);
          } else
            iter++;
        tmp.pop();
      }
      count++;
    }
    return 0;
  }

  bool compare(string &s1, string &s2) {
    bool flag = false;
    for (int i = 0; i < s1.size(); i++)
      if (s1[i] != s2[i])
        if (flag)
          return false;
        else
          flag = true;
    return flag;
  }
};

int main() {
  vector<string> v{"hot", "dot", "dog", "lot", "log", "cog"};
  auto r = Solution().ladderLength("hit", "cog", v);
  return 0;
}
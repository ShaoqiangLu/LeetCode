#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string tmp;
    stringstream ss(path);
    vector<string> v;
    while (getline(ss, tmp, '/')) {
      if (tmp == "..") {
        if (!v.empty())
          v.pop_back();
      } else if (tmp == "" || tmp == ".")
        continue;
      else
        v.push_back(tmp);
    }
    string res;
    for (string s : v)
      res += "/" + s;
    return res.empty() ? "/" : res;
  }

  string simplifyPath2(string path) {
    string tmp;
    stack<string> stack;
    int count = 0;
    path = path + '/';
    for (char c : path) {
      if (c == '/') {
        if (count != tmp.size() || count > 2) {
          stack.push(tmp);
        } else if (count == 2 && !stack.empty())
          stack.pop();
        tmp.clear();
        count = 0;
      } else if (c == '.') {
        count++;
        tmp += c;
      } else {
        tmp += c;
      }
    }
    string res;
    while (!stack.empty()) {
      res = '/' + stack.top() + res;
      stack.pop();
    }
    return res.size() ? res : "/";
  }
};

int main() {
  string r = Solution().simplifyPath("/home//foo/");
  return 0;
}
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    for (char &c : s)
      if (c == '(' || c == '[' || c == '{')
        stack.push(c);
      else if (!stack.empty() && c - stack.top() < 3 && stack.top() < c)
        stack.pop();
      else
        return false;
    return stack.empty();
  }
};

int main() {
  bool r = Solution().isValid("{{)}");
  return 0;
}
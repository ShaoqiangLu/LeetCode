#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    string res;
    for (int i = 0; i < numRows + 1; i++)
      for (int j = i; j < s.size(); j += numRows + 1)
        res += (s[j]);
    return res;
  }
};

int main() {
  string r = Solution().convert("PAYPALISHIRING", 3);
  return 0;
}
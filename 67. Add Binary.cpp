#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, c = 0;
    while (i >= 0 || j >= 0) {
      c = (i >= 0 ? a[i--] == '1' : 0) + (j >= 0 ? b[j--] == '1' : 0) + c;
      res = to_string(c % 2) + res;
      c /= 2;
    }
    if (c)
      res = to_string(1) + res;
    return res;
  }
};

int main() {
  string r = Solution().addBinary("1010", "1011");
  return 0;
}
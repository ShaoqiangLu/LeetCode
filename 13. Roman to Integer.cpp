#include <string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int res = 0;
    char last = 0;
    for (const char &c : s) {
      switch (c) {
      case 'M':
        res += last == 'C' ? 800 : 1000;
        break;
      case 'D':
        res += last == 'C' ? 300 : 500;
        break;
      case 'C':
        res += last == 'X' ? 80 : 100;
        break;
      case 'L':
        res += last == 'X' ? 30 : 50;
        break;
      case 'X':
        res += last == 'I' ? 8 : 10;
        break;
      case 'V':
        res += last == 'I' ? 3 : 5;
        break;
      case 'I':
        res += 1;
        break;
      }
      last = c;
    }
    return res;
  }
};

int main() {
  int r = Solution().romanToInt("MCMXCIV");
  return 0;
}
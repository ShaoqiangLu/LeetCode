#include <string>

using namespace std;

const static int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const static string sym[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I"};
class Solution {
public:
  string intToRoman(int num) {
    string res;
    for (int i = 0; num > 0; i++)
      while (num >= val[i]) {
        num -= val[i];
        res.append(sym[i]);
      }
    return res;
  }
};

int main() {
  string r = Solution().intToRoman(1994);
  return 0;
}
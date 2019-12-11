#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    string res;
    for (int i = num1.size() - 1; i >= 0; i--) {
      int flag = 0;
      string tmp_str;
      for (int j = num2.size() - 1; j >= 0; j--) {
        int tmp = (num1[i] - '0') * (num2[j] - '0') + flag;
        flag = tmp / 10;
        tmp_str.insert(tmp_str.begin(), tmp % 10 + '0');
      }
      if (flag)
        tmp_str.insert(tmp_str.begin(), flag + '0');
      add(res, tmp_str, );
    }
    return res;
  }

  void add(string &res, string &tmp_str, int start) {
    int flag = 0;
    string r;
    for (int i = 1; res.size() >= i || tmp_str.size() >= i; i++) {
      int tmp = (res.size() < i ? 0 : (res[res.size() - i] - '0')) +
                (tmp_str.size() < i ? 0 : (tmp_str[tmp_str.size() - i] - '0')) +
                flag;
      flag = tmp / 10;
      r.insert(r.begin(), tmp % 10 + '0');
    }
    if (flag)
      r.insert(r.begin(), '1');
    res = r;
  }
};

int main() {
  string r = Solution().multiply("55", "33");
  return 0;
}
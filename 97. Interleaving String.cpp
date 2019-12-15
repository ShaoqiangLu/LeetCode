#include <deque>
#include <string>

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    deque<char> d1, d2;
    int idx1 = 0, idx2 = 0, count = 0;
    for (char c : s3) {
      if (s1[idx1] == c && s2[idx2] == c) {
        d1.push_back(c);
        d2.push_back(c);
        idx1++;
        idx2++;
      } else if (s1[idx1] == c)
        idx1++;
      else if (s2[idx2] == c)
        idx2++;
      else if (count) {

      } else
        return false;
    }
  }
};

int main() {
  bool r = Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac");
  return 0;
}
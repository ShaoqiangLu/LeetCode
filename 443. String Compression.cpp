#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int compress(vector<char> &chars) {
    int i = 0, cur = 0;
    while (i < chars.size()) {
      int count = 0;
      chars[cur++] = chars[i];
      do {
        i++;
        count++;
      } while (i < chars.size() && chars[i - 1] == chars[i]);
      if (count > 1)
        for (char c : to_string(count))
          chars[cur++] = c;
    }
    return cur;
  }
};

int main() {
  vector<char> v{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  int r = Solution().compress(v);
  return 0;
}
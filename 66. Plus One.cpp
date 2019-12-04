#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; digits[i--] = 0)
      if (digits[i]++ < 9)
        return digits;
    digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main() {
  vector<int> v{1, 2, 3};
  vector<int> r = Solution().plusOne(v);
  return 0;
}
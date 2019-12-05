#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i = 0;
    for (int n : nums) {
      if (i < 2 || nums[i - 2] != n)
        nums[i++] = n;
    }
    return i;
  }
};

int main() {
  vector<int> v{};
  int r = Solution().removeDuplicates(v);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (!nums.size())
      return 0;
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[i] != nums[j])
        nums[++i] = nums[j];
    }
    return i + 1;
    for
  }
};

int main() {
  vector<int> v{};
  int r = Solution().removeDuplicates(v);
  return 0;
}
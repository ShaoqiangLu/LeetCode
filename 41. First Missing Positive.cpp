#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] != i + 1)
        return i + 1;
    return n + 1;
  }
};

int main() {
  vector<int> v{0, 1, 2};
  auto r = Solution().firstMissingPositive(v);
  return 0;
}
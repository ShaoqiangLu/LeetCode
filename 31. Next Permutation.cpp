#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1)
      return;
    int l = -1, r = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
      if (nums[i] < nums[i + 1]) {
        l = i;
        r = l + 1;
        break;
      }
    for (int i = r + 1; i < nums.size(); i++)
      if (nums[i] > nums[l] && nums[i] <= nums[r])
        r = i;
    if (l >= 0)
      swap(nums[l], nums[r]);
    reverse(nums.begin() + l + 1, nums.end());
    return;
  }
};

int main() {
  vector<int> v{1, 1};
  Solution().nextPermutation(v);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int l_idx = 0, r_idx = nums.size() - 1, idx = 0;
    while (idx <= r_idx) {
      if (nums[idx] == 0)
        swap(nums[l_idx++], nums[idx++]);
      else if (nums[idx] == 2)
        swap(nums[r_idx--], nums[idx]);
      else
        idx++;
    }
  }
};

int main() {
  vector<int> v{1, 0, 2, 2, 1, 0};
  Solution().sortColors(v);
  return 0;
}
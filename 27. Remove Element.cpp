#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int i = 0, n = nums.size() - 1;
    while (i <= n) {
      if (nums[i] == val)
        nums[i] = nums[n--];
      else
        i++;
    }
    return i;
  }
};

int main() {
  vector<int> v{3, 2, 2, 3};
  int r = Solution().removeElement(v, 3);
  return 0;
}
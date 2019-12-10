#include <vector>

using namespace std;

class Solution {
public:
  // BFS
  int jump(vector<int> &nums) {
    int n = nums.size() - 1, count = 0, first = 0, last = 0;
    while (last < n) {
      count++;
      int far = last;
      for (int i = first; i <= last; i++)
        far = max(far, i + nums[i]);
      first = last + 1;
      last = far;
    }
    return count;
  }
  // greedy(timeout)
  int jump2(vector<int> &nums) {
    int pos = nums.size() - 1, count = 0;
    for (int i = 0; i < pos; i++) {
      if (i + nums[i] >= pos) {
        pos = i;
        count++;
        i = -1;
      }
    }
    return count;
  }
};

int main() {
  vector<int> v{2, 3, 1, 1, 4};
  bool r = Solution().jump(v);
  return 0;
}
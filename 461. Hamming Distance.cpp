#include <vector>

using namespace std;

class Solution {
public:
  int totalHammingDistance(vector<int> &nums) {
    int r = 0, size = nums.size();
    for (int i = 0; i < 30; i++) {
      int count = 0;
      for (const int &n : nums) {
        if (n & (1 << i))
          count++;
      }
      r += count * (size - count);
    }
    return r;
  }
};

int main() {
  vector<int> v{8, 9, 10};
  int r = Solution().totalHammingDistance(v);
  return 0;
}
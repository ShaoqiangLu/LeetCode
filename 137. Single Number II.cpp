#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {}
};

int main() {
  vector<int> v{8, 9, 8};
  int r = Solution().singleNumber(v);
  return 0;
}
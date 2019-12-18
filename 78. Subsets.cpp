#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res = {{}};
    1 << nums.size();
    for (int i = 0; i <= ; i++) {
      vector<int> tmp;
      int count = 0, bits = i;
      while (bits) {
        if (bits & 1)
          tmp.push_back(nums[count]);
        bits >>= 1;
        count++;
      }
      res.push_back(tmp);
    }
    return res;
  }
};

int main() { vector<int> v{1, 2, 3}; }
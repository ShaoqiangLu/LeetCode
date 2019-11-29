#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];
      if (map.count(val)) {
        return {map[val], i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  vector<int> nums{1, 2, 3, 4, 5};
  int target = 8;
  vector<int> result = Solution().twoSum(nums, target);
  return 0;
}
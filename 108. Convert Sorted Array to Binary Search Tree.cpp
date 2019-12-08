#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }

  TreeNode *sortedArrayToBST(vector<int> &nums, int first, int last) {
    if (first > last)
      return nullptr;
    int mid = (last - first) / 2 + first;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, first, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, last);
    return root;
  }
};

int main() {
  vector<int> v{-10, -3, 0, 5, 9};
  TreeNode *root = Solution().sortedArrayToBST(v);
  return 0;
}
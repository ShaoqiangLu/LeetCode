#include "TreeNode.h"
#include <climits>

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root->left, INT_MIN, root->val) &&
           isValidBST(root->right, root->val, INT_MAX);
  }

  bool isValidBST(TreeNode *root, int low, int high) {
    if (!root)
      return true;
    if (root->val <= low)
      return false;
    if (root->val >= high)
      return false;
    return isValidBST(root->left, low, root->val) &&
           isValidBST(root->right, root->val, high);
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(0);
  t1->right = new TreeNode(3);
  bool r = Solution().isValidBST(t1);
  return 0;
}
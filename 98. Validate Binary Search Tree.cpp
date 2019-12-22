#include "TreeNode.h"

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    if (!isValidBST(root->left))
      return false;
      if()
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  bool r = Solution().isValidBST(t1, t2);
  return 0;
}
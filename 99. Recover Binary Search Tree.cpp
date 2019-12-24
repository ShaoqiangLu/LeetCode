#include "TreeNode.h"

class Solution {
public:
  void recoverTree(TreeNode *root) {
    if (root->left && root->left->val > root->val)
  }
};

int main() {
  TreeNode *t = new TreeNode(1);
  Solution().recoverTree(t);
  return 0;
}
#include "TreeNode.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root)
      return false;
    if (!root->left && !root->right)
      return sum == root->val;
    else
      return hasPathSum(root->left, sum - root->val) ||
             hasPathSum(root->right, sum - root->val);
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  t1->right = new TreeNode(2);
  t1->right->right = new TreeNode(2);
  bool r = Solution().hasPathSum(t1, 5);
  return 0;
}
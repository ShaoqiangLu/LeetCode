#include "TreeNode.h"
#include <stack>

using namespace std;

class Solution {
public:
  // recursive
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    else if (!p || !q)
      return false;
    else
      return p->val == q->val && isSameTree(p->left, q->left) &&
             isSameTree(p->right, q->right);
  }
  // stack queue
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  TreeNode *t2 = new TreeNode(1);
  bool r = Solution().isSameTree(t1, t2);
  return 0;
}
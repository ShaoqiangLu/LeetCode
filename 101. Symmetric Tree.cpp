#include "TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    TreeNode *l, *r;
    while (!q.empty()) {
      l = q.front();
      q.pop();
      r = q.front();
      q.pop();
      if (!l && !r)
        continue;
      else if (!l || !r)
        return false;
      else if (l->val != r->val)
        return false;
      q.push(l->left);
      q.push(r->right);
      q.push(l->right);
      q.push(r->left);
    }
    return true;
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  TreeNode *t2 = new TreeNode(1);
  bool r = Solution().isSymmetric(t1);
  return 0;
}
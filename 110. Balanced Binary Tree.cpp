#include "TreeNode.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool isBalanced(TreeNode *root) { return isBalanced(root, 0); }

  bool isBalanced(TreeNode *root, int height) {
    if (!root)
      return true;
    else if (!root->left || !root->right)
      if (m.empty())
        m.push_back(height);
      else if (m.size() == 1)
        if (abs(m[0] - height) <= 1)
          m.push_back(height);
        else
          return false;
      else {
        if (!(abs(m[0] - height) <= 1 && abs(m[1] - height) <= 1))
          return false;
      }
    bool res = true;
    if (root->left)
      res &= isBalanced(root->left, height + 1);
    if (root->right)
      res &= isBalanced(root->right, height + 1);
    return res;
  }

private:
  vector<int> m;
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  t1->right = new TreeNode(2);
  t1->right->right = new TreeNode(2);
  bool r = Solution().isBalanced(t1);
  return 0;
}
#include "TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int count = 1;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        root = q.front();
        if (!root->left && !root->right)
          return count;
        if (root->left)
          q.push(root->left);
        if (root->right)
          q.push(root->right);
        q.pop();
      }
      count++;
    }
    return -1;
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  t1->right = new TreeNode(2);
  t1->right->right = new TreeNode(2);
  auto r = Solution().minDepth(t1);
  return 0;
}
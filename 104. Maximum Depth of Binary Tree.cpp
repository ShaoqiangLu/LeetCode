#include "TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
  }
  int maxDepth(TreeNode *root, int depth) {
    return root ? max(maxDepth(root->left, depth + 1),
                      maxDepth(root->right, depth + 1))
                : depth;
  }
};

int main() {
  TreeNode *t1 = new TreeNode(1);
  TreeNode *t2 = new TreeNode(1);
  int r = Solution().maxDepth(t1);
  return 0;
}
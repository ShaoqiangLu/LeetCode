#include "ListNode.h"
#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    this->head = head;
    int count = 0;
    while (head) {
      head = head->next;
      count++;
    }
    return sortedListToBST(0, count - 1);
  }

  TreeNode *sortedListToBST(int first, int last) {
    if (first > last)
      return nullptr;
    int mid = (last - first) / 2 + first;
    TreeNode *left = sortedListToBST(first, mid - 1);
    TreeNode *node = new TreeNode(head->val);
    node->left = left;
    head = head->next;
    node->right = sortedListToBST(mid + 1, last);
    return node;
  }

private:
  ListNode *head;
};

int main() {
  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);
  TreeNode *root = Solution().sortedListToBST(l);
  return 0;
}
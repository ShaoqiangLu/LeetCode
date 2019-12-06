#include "ListNode.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur && cur->next) {
      if (cur->val == cur->next->val)
        cur->next = cur->next->next;
      cur = cur->next;
    }
    return head;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);
  l1->next->next->next = new ListNode(5);
  ListNode *r = Solution().deleteDuplicates(l1);
  return 0;
}
#include "ListNode.h"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    while (n-- > 0)
      head = head->next;
    while (head) {
      head = head->next;
      pre = pre->next;
    }
    pre->next = pre->next->next;
    return dummy.next;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);
  ListNode *r = Solution().removeNthFromEnd(l1, 2);
  return 0;
}
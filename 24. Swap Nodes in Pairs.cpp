#include "ListNode.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head)
      return head;
    ListNode *l = head, *r = head->next, *res = r;
    while (l && r) {
      l->next = r->next;
      r->next = l;
      if (l->next) {
        r = l->next->next;
        ListNode *t = l->next;
        l->next = l->next->next;
        l = t;
      } else {
        /* code */
      }
    }
  }
};

int main() {
  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);
  ListNode *r = Solution().swapPairs(l);
  return 0;
}
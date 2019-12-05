#include "ListNode.h"

// iterative(dummy node or not) and recursive
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode **pp = &head, *l, *r;
    while ((l = *pp) && (r = l->next)) {
      l->next = r->next;
      r->next = l;
      *pp = r; // key
      pp = &(l->next);
    }
    return head;
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
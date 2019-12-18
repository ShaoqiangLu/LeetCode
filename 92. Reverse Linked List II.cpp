#include "ListNode.h"

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    while (--m && --n)
      pre = pre->next;
    ListNode *cur = pre->next, *next = cur->next, *tail = cur;
    while (--n) {
      ListNode *tmp = next->next;
      next->next = cur;
      cur = next;
      next = tmp;
    }
    tail->next = next;
    pre->next = cur;
    return dummy.next;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);
  l1->next->next->next = new ListNode(5);
  ListNode *r = Solution().reverseBetween(l1, 2, 3);
  return 0;
}
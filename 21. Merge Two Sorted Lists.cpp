#include "ListNode.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode res(0);
    ListNode *tmp = &res;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tmp->next = l1;
        l1 = l1->next;
      } else {
        tmp->next = l2;
        l2 = l2->next;
      }
      tmp = tmp->next;
    }
    tmp->next = l1 ? l1 : l2;
    return res.next;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(4);
  ListNode *r = Solution().mergeTwoLists(l1, l2);
  return 0;
}
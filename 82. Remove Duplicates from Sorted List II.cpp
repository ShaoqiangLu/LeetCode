#include "ListNode.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy(0);
    ListNode *pre = &dummy, *cur = head;
    while (cur) {
      while (cur->next && cur->val != cur->next->val) {
        pre->next = cur;
        pre = cur;
        cur = cur->next;
      }
      if (!cur->next) {
        pre->next = cur;
        break;
      }
      while (cur->next && cur->val == cur->next->val)
        cur = cur->next;
      cur = cur->next;
      pre->next = cur;
    }
    return dummy.next;
  }
  // concise
  ListNode *deleteDuplicates2(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy, *cur = head, *next;
    while (cur) {
      next = cur->next;
      if (next && cur->val == next->val) {
        while (next && cur->val == next->val)
          next = next->next;
        cur = next;
        pre->next = cur;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    return dummy.next;
  }
};

int main() {
  ListNode *l = new ListNode(1);
  l->next = new ListNode(1);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(3);
  l->next->next->next->next = new ListNode(4);
  auto r = Solution().deleteDuplicates2(l);
  return 0;
}
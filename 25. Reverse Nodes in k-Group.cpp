#include "ListNode.h"

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *l = head, *r = head, **pp = &head;
    while ((l = r) && (r = r->next) && checkLength(l, k)) {
      ListNode *first = l;
      for (int i = 1; i < k; i++) {
        ListNode *tmp = r->next;
        r->next = l;
        l = r;
        r = tmp;
      }
      *pp = l;
      pp = &(first->next);
    }
    *pp = l;
    return head;
  }

  bool checkLength(ListNode *head, int k) {
    int count = 0;
    while (head && count < k) {
      count++;
      head = head->next;
    }
    return count == k;
  }
};

int main() {
  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);
  ListNode *r = Solution().reverseKGroup(l, 3);
  return 0;
}
#include "ListNode.h"

class Solution {
public:
  // brilliant solution
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next)
      return head;
    ListNode *tail = head;
    int length = 1;
    while (tail->next) {
      length++;
      tail = tail->next;
    }
    tail->next = head;
    k = k % length;
    for (int i = 0; i < length - k; i++)
      tail = tail->next;
    head = tail->next;
    tail->next = nullptr;
    return head;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);
  l1->next->next->next = new ListNode(5);
  ListNode *r = Solution().rotateRight(l1, 5);
  return 0;
}
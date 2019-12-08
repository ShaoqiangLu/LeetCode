#include "ListNode.h"

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
        return true;
    }
    return false;
  }
};

int main() {
  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = l;
  bool r = Solution().hasCycle(l);
  return 0;
}
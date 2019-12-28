#include "ListNode.h"

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (!head)
      return true;
    ListNode *fast = head->next, *slow = head, *next = head->next, *tmp;
    slow->next = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      tmp = next->next;
      next->next = slow;
      slow = next;
      next = tmp;
    }
    if (!fast)
      slow = slow->next;
    while (slow) {
      if (slow->val != next->val)
        return false;
      slow = slow->next;
      next = next->next;
    }
    return true;
  }
};

int main() {
  ListNode *l = new ListNode(4);
  l->next = new ListNode(2);
  l->next->next = new ListNode(1);
  l->next->next->next = new ListNode(3);
  auto r = Solution().isPalindrome(l);
  return 0;
}
#include "ListNode.h"

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (!head)
      return true;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *cur = slow, *next = cur->next, *tmp;
    cur->next = nullptr;
    while (next) {
      tmp = next->next;
      next->next = cur;
      cur = next;
      next = tmp;
    }
    while (cur) {
      if (head->val != cur->val)
        return false;
      head = head->next;
      cur = cur->next;
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
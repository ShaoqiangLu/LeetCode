#include "ListNode.h"

using namespace std;

class Solution {
public:
  // time O(nlogn) space O(1)
  ListNode *sortList(ListNode *head) {
    while () {
        }
  }

  // time O(nlogn) space O(logn)
  ListNode *sortListRecursion(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    fast = slow->next;
    slow->next = nullptr;

    head = sortList(head);
    fast = sortList(fast);

    ListNode dummy = ListNode(0);
    ListNode *idx = &dummy;
    while (head && fast) {
      if (head->val < fast->val) {
        idx->next = head;
        idx = idx->next;
        head = head->next;
      } else {
        idx->next = fast;
        idx = idx->next;
        fast = fast->next;
      }
    }
    if (head)
      idx->next = head;
    if (fast)
      idx->next = fast;
    return dummy.next;
  }
};

int main() {
  ListNode *l = new ListNode(4);
  l->next = new ListNode(2);
  l->next->next = new ListNode(1);
  l->next->next->next = new ListNode(3);
  ListNode *r = Solution().sortList(l);
  return 0;
}
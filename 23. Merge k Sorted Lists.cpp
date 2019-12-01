#include "ListNode.h"
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;
    for (int len = lists.size(); len > 1; len = (len + 1) / 2)
      for (int i = 0; i < len / 2; i++)
        lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
    return lists.front();
  }

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
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);
  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  ListNode *l3 = new ListNode(2);
  l3->next = new ListNode(6);
  vector<ListNode *> lists{nullptr, l1, nullptr, l2, l3};
  ListNode *r = Solution().mergeKLists(lists);
  return 0;
}
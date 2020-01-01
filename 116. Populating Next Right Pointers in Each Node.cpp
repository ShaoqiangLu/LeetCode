#include "Node.h"
#include <queue>

using namespace std;

class Solution {
public:
  Node *connect(Node *root) {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n - 1; i++) {
        Node *node1 = q.back();
        q.pop();
        Node *node2 = q.back();
        node1->next = node2;
      }
      q.pop();
    }
  }
};

int main() { return 0; }
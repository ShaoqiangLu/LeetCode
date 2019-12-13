#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct TrieNode {
  char c;
  vector<TrieNode *> links;
  bool end = false;
  TrieNode(char c) : c(c) {}
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() { root = new TrieNode(0); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *node = root;
    bool flag = true;
    for (int i = 0; i < word.size();) {
      if (flag) {
        TrieNode *tmp = find_next(word[i], node);
        if (tmp) {
          node = tmp;
          i++;
        } else
          flag = false;
      } else {
        TrieNode *tmp = new TrieNode(word[i++]);
        node->links.push_back(tmp);
        node = tmp;
      }
    }
    node->end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) { return find(word)->end; }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) { return find(prefix)->c; }

private:
  TrieNode *root;
  TrieNode *find_next(char c, TrieNode *node) {
    for (auto next_node : node->links) {
      if (next_node->c == c)
        return next_node;
    }
    return nullptr;
  }

  TrieNode *find(string word) {
    TrieNode *node = root;
    for (char c : word) {
      TrieNode *tmp = find_next(c, node);
      if (tmp)
        node = tmp;
      else
        return root;
    }
    return node;
  }
};

int main() {
  Trie *obj = new Trie();
  obj->insert("apple");
  bool param_2 = obj->search("apple");
  bool param_3 = obj->startsWith("app");
  return 0;
}
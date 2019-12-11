#include <string>
#include <vector>

using namespace std;

class KMP {
private:
  string pat;
  vector<vector<int>> dfa;

public:
  KMP(string pat) {
    this->pat = pat;
    int M = pat.size(), R = 256;
    dfa = vector<vector<int>>(R, vector<int>(M));
    dfa[pat[0]][0] = 1;
    for (int X = 0, j = 1; j < M; j++) {
      for (int c = 0; c < R; c++)
        dfa[c][j] = dfa[c][X];
      dfa[pat[j]][j] = j + 1;
      X = dfa[pat[j]][X];
    }
  }

  int search(string txt) {
    int i, j, N = txt.size(), M = pat.size();
    for (i = j = 0; i < N && j < M; i++)
      j = dfa[txt[i]][j];
    return j == M ? i - M : N;
  }
};

int main() {
  KMP kmp("ababac");
  int r = kmp.search("ababac");
  return 0;
}

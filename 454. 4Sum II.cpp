#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    int count = 0;
    unordered_map<int, int> map;
    for (int a : A)
      for (int b : B)
        ++map[a + b];
    for (int c : C)
      for (int d : D) {
        auto iter = map.find(-c - d);
        if (iter != map.end())
          count += iter->second;
      }
    return count;
  }
};

int main() {
  vector<int> A{0, -1, -1, -1, 0, 1, 1}, B{-1, -1, 1, 0, 1, -1, 0},
      C{0, 1, 0, -1, 1, 0, 1}, D{1, 0, -1, -1, 1, 0, -1};
  int result = Solution().fourSumCount(A, B, C, D);
  return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, idx = m + n - 1;
    while (i >= 0 && j >= 0)
      if (nums1[i] <= nums2[j])
        nums1[idx--] = nums2[j--];
      else
        nums1[idx--] = nums1[i--];
    while (j >= 0)
      nums1[idx--] = nums2[j--];
  }
};

int main() {
  vector<int> v1{1, 4, 7, 0, 0, 0};
  vector<int> v2{2, 3, 8};
  Solution().merge(v1, 3, v2, 3);
  return 0;
}
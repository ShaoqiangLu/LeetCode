#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int l, r;
    l = min(nums1.front(), nums2.front());
    r = max(nums2.back(), nums2.back());
    whi
  }
};

int main() {
  vector<int> v{1, 2, 3};
  auto r = Solution().findMedianSortedArrays(v, v);
  return 0;
}
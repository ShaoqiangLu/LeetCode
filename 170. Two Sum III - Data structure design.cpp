#include <unordered_map>
#include <vector>

using namespace std;

class TwoSum {
public:
  void add(int num) { m[num]++; }
  bool find(int target) {
    for (auto p : m) {
      int val = target - p.first;
      if (m.count(val) && (val != p.first || p.second > 1))
        return true;
    }
    return false;
  }

private:
  unordered_map<int, int> m;
};

int main() {
  TwoSum twoSum;
  twoSum.add(1);
  twoSum.add(3);
  twoSum.add(5);
  bool b1 = twoSum.find(4);
  bool b2 = twoSum.find(7);
  return 0;
}
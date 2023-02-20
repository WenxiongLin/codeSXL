#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    // 使用双指针法，快指针每次往后+1，慢指针当不匹配时再往后+1，匹配时跳过
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
      if (val != nums[fastIndex]) {
        nums[slowIndex++] = nums[fastIndex];
      }
    }
    return slowIndex;
  }
};
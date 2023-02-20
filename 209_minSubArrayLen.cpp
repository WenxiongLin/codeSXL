#include <vector>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    // 使用双指针滑动窗口
    int left = 0, right = 0, sum = 0;
    int size = nums.size();
    bool flag = false;
    // right向前一步
    for (; right < nums.size(); ++right) {
      sum += nums[right];
      // 当总和超过target时，移动左指针，直到总和小于target时跳出
      while (sum >= target) {
        if (size > right - left + 1) size = right - left + 1;
        sum -= nums[left];
        left++;
        flag = true;
      }
    }
    return flag ? size : 0;
  }
};
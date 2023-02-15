#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // 跟15三数之和类似，for循环再嵌套for循环先确定前两位数字
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
      // target有可能小于0，所以不能直接用nums[i] > target
      if (nums[i] > target && nums[i] >= 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < nums.size(); ++j) {
        if ((long)nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
            right--;
          else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
            left++;
          else {
            result.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[right] == nums[right - 1]) right--;
            while (left < right && nums[left] == nums[left + 1]) left++;
            left++;
            right--;
          }
        }
      }
    }
    return result;
  }
};
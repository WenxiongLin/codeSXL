#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
      // 第一个数字大于0则不可能符合
      if (nums[i] > 0) break;
      // 去重第一个元素
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      // 使用双指针
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] > 0)
          right--;
        else if (nums[i] + nums[left] + nums[right] < 0)
          left++;
        else {
          result.push_back({nums[i], nums[left], nums[right]});
          // 去重后两个元素
          while (left < right && nums[right] == nums[right - 1]) right--;
          while (left < right && nums[left] == nums[left + 1]) left++;
          left++;
          right--;
        }
      }
    }
    return result;
  }
};
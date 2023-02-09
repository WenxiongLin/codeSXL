#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // vector<int> r;
    // for(int i = 0; i < nums.size(); ++i){
    //     for(int j = 0; j < nums.size(); ++j){
    //         if((nums[i]+nums[j] == target) && (i != j)){
    //             r.push_back(i);
    //             r.push_back(j);
    //             return r;
    //         }
    //     }
    // }
    // return r;

    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      auto iter = map.find(target - nums[i]);
      if (iter != map.end()) {
        return {iter->second, i};
      }
      map.insert({nums[i], i});
    }
    return {};
  }
};
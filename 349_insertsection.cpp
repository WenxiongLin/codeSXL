#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // set<int> setNums1, setNums2;
        // for(auto i : nums1) setNums1.insert(i);
        // for(auto i : nums2) setNums2.insert(i);
        // vector<int> result;
        // auto i = setNums1.begin(), j = setNums2.begin();
        // while(i != setNums1.end() && j != setNums2.end()){
        //     if(*i < *j){
        //         i++;
        //     } else if(*i > *j) {
        //         j++;
        //     } else {
        //         result.push_back(*i);
        //         i++;
        //         j++;
        //     }
        // }
        // return result;

        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());

        // set<int> setNums1;
        // for(auto i : nums1) setNums1.insert(i);
        // vector<int> result;
        // for(int i = 0; i < nums2.size(); ++i){
        //     if(setNums1.find(nums2[i]) != setNums1.end()) result.push_back(nums2[i]);
        // }
        // set<int> setR(result.begin(), result.end());
        // result = vector<int>(setR.begin(), setR.end());
        // return result;
    }
};
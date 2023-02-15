#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    // 使用哈希法，先求两个数之和的值，再去找相加等于0的情况
    unordered_map<int, int> umap;
    for (auto i : nums1) {
      for (auto j : nums2) {
        umap[i + j]++;
      }
    }
    int count = 0;
    for (auto i : nums3) {
      for (auto j : nums4) {
        if (umap.find(0 - i - j) != umap.end()) {
          count += umap[0 - i - j];
        }
      }
    }
    return count;
  }
};
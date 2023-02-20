#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    // 双指针法
    vector<int> result(A.size());
    int left = 0;
    int right = A.size() - 1;
    int k = right;
    while (left <= right) {
      if (A[left] * A[left] < A[right] * A[right]) {
        result[k--] = A[right] * A[right];
        right--;
      } else {
        result[k--] = A[left] * A[left];
        left++;
      }
    }
    return result;
  }
};
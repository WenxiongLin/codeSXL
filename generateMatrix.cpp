#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    // vector<vector<int>> result(0, vector<int>(0, n));
    vector<vector<int>> result;
    result.resize(n);
    for (int i = 0; i < n; ++i) {
      result[i].resize(n);
    }
    int l = 0, r = n - 1, t = 0, b = n - 1;
    int num = 1, target = n * n;
    while (num <= target) {
      // 从左到右
      for (int i = l; i <= r; ++i) result[t][i] = num++;
      t++;
      // 从上到下
      for (int i = t; i <= b; ++i) result[i][r] = num++;
      r--;
      // 从右到左
      for (int i = r; i >= l; --i) result[b][i] = num++;
      b--;
      // 从下到上
      for (int i = b; i >= t; --i) result[i][l] = num++;
      l++;
    }
    return result;
  }
};

int main() {
  int n = 3;
  vector<vector<int>> result;
  Solution solution;
  result = solution.generateMatrix(n);
  for (auto r1 : result) {
    for (auto r : r1) {
      cout << r << " ";
    }
    cout << endl;
  }
}
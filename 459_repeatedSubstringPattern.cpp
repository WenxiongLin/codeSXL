#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  void getNext(int* next, const string& s) {
    int j = 0;
    next[0] = 0;
    int len = s.size();
    for (int i = 1; i < len; ++i) {
      // 不匹配
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];
      }
      if (s[i] == s[j]) {
        j++;
      }
      next[i] = j;
    }
  }

  bool repeatedSubstringPattern(string s) {
    // 使用库函数
    // string t = s + s;
    // t.erase(t.begin());
    // t.erase(t.end() - 1);
    // return t.find(s) != string::npos;

    // 使用KMP算法
    // int len = s.size();
    if (s.size() == 0) return false;
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    // len - 最长子序列 能够整除 len，则剩下的字符就是重复的子串
    if (next[len - 1] != -1 && (len % (len - next[len - 1])) == 0) return true;
    return false;
  }
};

int main() {
  Solution s;
  cout << s.repeatedSubstringPattern("ababababaab");
  return 0;
}
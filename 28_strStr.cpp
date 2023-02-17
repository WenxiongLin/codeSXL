#include <iostream>
#include <string>
using namespace std;

// KMP算法
class Solution {
 public:
  // 根据最长相等前后缀来确定next数组
  void getNext(int* next, const string& s) {
    next[0] = 0;
    // j即表示下标又表示前缀中相等的字符长度
    int j = 0;
    // i从1开始
    for (int i = 1; i < s.size(); ++i) {
      // 前后缀不相等则向前回退，直到再次相等
      while (j > 0 && s[j] != s[i]) {
        j = next[j - 1];
      }
      // 前后缀相等则j++
      if (s[j] == s[i]) j++;
      // 将前缀的长度（j）赋值给next数组
      next[i] = j;
    }
  }

  int strStr(string haystack, string needle) {
    int next[needle.size()];
    getNext(next, needle);
    int j = next[0];
    for (int i = 0; i < haystack.size(); ++i) {
      // 字符不相等根据next数组回退到相等的位置
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      // 字符匹配则向前一步
      if (haystack[i] == needle[j]) {
        j++;
      }
      // 直到模式串全部完成匹配，则找到/*  */
      if (j == needle.size()) {
        return i - needle.size() + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  int r = s.strStr("ababababababf", "abababf");
  cout << r << endl;
  return 0;
}
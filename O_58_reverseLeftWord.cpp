#include <algorithm>
#include <string>
using namespace std;

class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    // // 先翻转前n个字符
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
    // 再翻转剩下的字符
    for (int i = n, j = s.size() - 1; i < j; ++i, --j) {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
    // 最后翻转整个字符
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
    return s;

    // reverse(s.begin(), s.begin() + n);
    // reverse(s.begin() + n, s.end());
    // reverse(s.begin(), s.end());
    // return s;
  }
};
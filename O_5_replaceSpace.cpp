#include <string>
using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    // 辅助空间O(n)
    // string str;
    // for(int i = 0; i < s.size(); ++i) {
    //     if(s[i] == ' ') str += "%20";
    //     else str += s[i];
    // }
    // return str;

    // 辅助空间O(1)
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') count++;
    }
    int len = s.size();
    s.resize(len + 2 * count);
    for (int i = len - 1, j = s.size() - 1; i >= 0; i--, j--) {
      if (s[i] == ' ') {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      } else {
        s[j] = s[i];
      }
    }
    return s;
  }
};
#include <deque>
#include <string>
using namespace std;

class Solution {
 public:
  // 翻转单个单词
  void reverseStr(string& s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      swap(s[i], s[j]);
    }
  }
  // 去除多余的空格
  void removeExtraSpaces(string& s) {
    int slow = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        if (slow > 0) s[slow++] = ' ';
        while (i < s.size() && s[i] != ' ') {
          s[slow++] = s[i++];
        }
      }
    }
    s.resize(slow);
  }

  string reverseWords(string s) {
    // removeExtraSpaces(s);
    // reverseStr(s, 0, s.size() - 1);
    // int start = 0;
    // for(int i = 0; i <= s.size(); ++i) {
    //     if(i == s.size() || s[i] == ' ') {
    //         reverseStr(s, start, i - 1);
    //         start = i + 1;
    //     }
    // }
    // return s;

    // 使用队列的方法
    int left = 0, right = s.size() - 1;
    // 去掉字符串开头的空白字符
    while (left <= right && s[left] == ' ') ++left;
    // 去掉字符串末尾的空白字符
    while (left <= right && s[right] == ' ') --right;
    deque<string> d;
    string word;
    // 从字符串中截取单词
    while (left <= right) {
      char c = s[left];
      if (word.size() && c == ' ') {
        // 将单词 push 到队列的头部
        d.push_front(move(word));
        word = "";
      } else if (c != ' ') {
        word += c;
      }
      ++left;
    }
    d.push_front(move(word));

    string ans;
    while (!d.empty()) {
      ans += d.front();
      d.pop_front();
      if (!d.empty()) ans += ' ';
    }
    return ans;
  }
};
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  string removeDuplicates(string s) {
    // stack<char> st;
    // for(char c : s) {
    //     if(st.empty()) st.push(c);
    //     else if(st.top() == c) st.pop();
    //     else st.push(c);
    // }
    // string result = "";
    // while(!st.empty()) {
    //     result += st.top();
    //     st.pop();
    // }
    // reverse(result.begin(), result.end());
    // return result;

    // 直接将字符串当作栈
    string result = "";
    for (char c : s) {
      if (result.empty() || result.back() != c)
        result += c;
      else
        result.pop_back();
    }
    return result;
  }
};
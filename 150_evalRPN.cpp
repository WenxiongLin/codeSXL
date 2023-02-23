#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief 逆波兰表达式求值
   * 
   * @param tokens 
   * @return 表达式的值 
   */
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string c : tokens) {
      if (c == "+") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b + a);
      } else if (c == "-") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b - a);
      } else if (c == "*") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b * a);
      } else if (c == "/") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b / a);
      } else {
        st.push(stoi(c));
      }
    }
    return st.top();
  }
};
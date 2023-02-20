#include <stack>
using namespace std;

class MyQueue {
 public:
  // 维护一个输入栈和一个输出栈
  // 在队列中添加元素的时候只需要将元素添加到输入栈中
  // 在队列中移除队首元素的时候需要判断输出栈中元素是否为空，为空时将输入栈中的所有元素添加到输出栈，不为空时移除输出栈的栈顶元素
  stack<int> stIn;   // 输入栈
  stack<int> stOut;  // 输出栈

  MyQueue() {}

  // 添加元素
  void push(int x) { stIn.push(x); }

  // 移除队首元素
  int pop() {
    if (stOut.empty()) {
      while (!stIn.empty()) {
        stOut.push(stIn.top());
        stIn.pop();
      }
    }
    int result = stOut.top();
    stOut.pop();
    return result;
  }

  // 访问队首元素
  int peek() {
    int result = this->pop();
    stOut.push(result);
    return result;
  }

  // 判断队列是否为空
  bool empty() { return stIn.empty() && stOut.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
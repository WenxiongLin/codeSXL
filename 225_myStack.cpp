#include <queue>
using namespace std;

class MyStack {
 public:
  // // 维护两个队列，压入元素直接压入有元素的队列，移除元素时需进行一次搬运
  // queue<int> q1;
  // queue<int> q2;

  // MyStack() {

  // }

  // void push(int x) {
  //     if(q2.empty()) q1.push(x);
  //     else q2.push(x);
  // }

  // int pop() {
  //     if(q2.empty()){
  //         while(q1.size() != 1){
  //             q2.push(q1.front());
  //             q1.pop();
  //         }
  //         int result = q1.front();
  //         q1.pop();
  //         return result;
  //     } else {
  //         while(q2.size() != 1){
  //             q1.push(q2.front());
  //             q2.pop();
  //         }
  //         int result = q2.front();
  //         q2.pop();
  //         return result;
  //     }
  // }

  // int top() {
  //     int result = this->pop();
  //     cout << result << endl;
  //     if(q1.empty()) q2.push(result);
  //     else q1.push(result);
  //     return result;
  // }

  // bool empty() {
  //     return q1.empty() && q2.empty();
  // }

  // 维护一个队列，移除元素的时候将队首元素又添加到队尾
  queue<int> que;

  MyStack() {}

  void push(int x) { que.push(x); }

  int pop() {
    int size = que.size();
    size--;  // 需要留下队尾元素在队首
    while (size--) {
      que.push(que.front());
      que.pop();
    }
    int result = que.front();
    que.pop();
    return result;
  }

  int top() { return que.back(); }

  bool empty() { return que.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
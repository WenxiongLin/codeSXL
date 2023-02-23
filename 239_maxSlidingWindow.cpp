#include <deque>
#include <vector>
using namespace std;

class Solution {
 private:
  // 构建一个单调队列
  class MyQueue {
   public:
    deque<int> que;
    // 移除元素的时候，只有当元素的值等于队列出口元素的时候才移除
    void pop(int value) {
      if ((!que.empty()) && (que.front() == value)) {
        que.pop_front();
      }
    }
    // 添加元素时，维护队列为单调递减的
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value) {
      while ((!que.empty()) && (value > que.back())) {
        que.pop_back();
      }
      que.push_back(value);
    }
    int front() { return que.front(); }
  };

 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MyQueue my_que;
    vector<int> result;
    for (int i = 0; i < k; ++i) {
      my_que.push(nums[i]);
    }
    result.push_back(my_que.front());
    for (int i = k; i < nums.size(); ++i) {
      my_que.pop(nums[i - k]);
      my_que.push(nums[i]);
      result.push_back(my_que.front());
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(-1);
  nums.push_back(-3);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(7);
  vector<int> r = s.maxSlidingWindow(nums, 3);
  return 0;
}
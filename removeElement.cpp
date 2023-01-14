#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    // 创建虚拟头节点，以便删除头节点与其他节点保持一致
    ListNode* virtualHead = new ListNode();
    virtualHead->next = head;
    ListNode* cur = virtualHead;
    while (cur->next != NULL) {
      if (cur->next->val == val) {
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        // 释放内存
        delete tmp;
      } else {
        cur = cur->next;
      }
    }
    return virtualHead->next;
  }
};

int main() {
  int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 3};
  int len = sizeof(a) / sizeof(int);
  ListNode* head = new ListNode(a[0]);
  ListNode* tmp = head;
  for (int i = 1; i < len; ++i) {
    ListNode* newNode = new ListNode(a[i]);
    tmp->next = newNode;
    tmp = newNode;
  }

  Solution solution;
  ListNode* r = solution.removeElements(head, 100);
  while(r->next != NULL){
    cout << r->val << ",";
    r = r->next;
  }
  cout << r->val << endl;

  return 0;
}
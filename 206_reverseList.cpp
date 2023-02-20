class Solution {
 private:
  // 定义链表节点结构体
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
  };

  ListNode* reverseList(ListNode* head) {
    // 保存cur的下一个节点
    ListNode* temp;
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur) {
      // 保存一下 cur的下一个节点，因为接下来要改变cur->next
      temp = cur->next;
      // 翻转操作
      cur->next = pre;
      // 更新pre 和 cur指针
      pre = cur;
      cur = temp;
    }
    return pre;
  }
};
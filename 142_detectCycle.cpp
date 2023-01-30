
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 使用辅助空间O（n）完成，遍历一次
        // ListNode* dummyHead = new ListNode(0);
        // dummyHead->next = head;
        // map<ListNode*, bool> visited;
        // ListNode* cur = dummyHead;
        // while(visited.find(cur->next) == visited.end()){
        //     if(cur->next == nullptr){
        //         return nullptr;
        //     }
        //     visited[cur->next] = true;
        //     cur = cur->next;
        // }
        // return cur->next;

        // 使用O（1）完成
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            //有环相遇，从头节点出发与慢指针同时移动一步，相遇点为入口
            if(fast == slow){
                ListNode* index1 = slow;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        //无环退出
        return nullptr;
    }
};
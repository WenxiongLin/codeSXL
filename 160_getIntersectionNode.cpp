
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* curA = headA;
        // ListNode* curB = headB;
        // while(curA != nullptr){
        //     curB = headB;
        //     while(curB != nullptr){
        //         if(curA == curB){
        //             return curA;
        //         }
        //         curB = curB->next;
        //     }
        //     curA = curA->next;
        // }
        // return nullptr;

        //假定A链表为长链表
        ListNode* longList = headA;
        ListNode* shortList = headB;

        //找到两个链表的长度
        int longLen = 0, shortLen = 0;
        while(longList){
            longList = longList->next;
            longLen++;
        }
        while(shortList){
            shortList = shortList->next;
            shortLen++;
        }

        //确定长链表和短链表
        longList = headA;
        shortList = headB;
        if(shortLen > longLen){
            int tmp = shortLen;
            shortLen = longLen;
            longLen = tmp;
            shortList = headA;
            longList = headB;
        }

        //尾部对齐
        int gap = longLen - shortLen;
        while(gap--){
            longList = longList->next;
        }

        while(longList){
            if(longList == shortList) return longList;
            longList = longList->next;
            shortList = shortList->next; 
        }

        return nullptr;
    }
};
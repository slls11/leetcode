class Solution {
public:
    /* O(n+m), Space: (1)*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA; ListNode* ptrB = headB;
        
        while (ptrA != ptrB){
            if (ptrA == nullptr) ptrA = headB;
            else ptrA = ptrA->next;
            
            if (ptrB == nullptr) ptrB = headA;
            else ptrB = ptrB->next;
        }
        
    return ptrA;
    }
};

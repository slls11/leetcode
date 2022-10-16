class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* back = nullptr; 
        ListNode* middle = head; 
        ListNode* front = head;
        
        while (front != nullptr){
            front = front->next;
            middle->next = back;
            back = middle;
            middle = front;
        }

    return back;
    }
};

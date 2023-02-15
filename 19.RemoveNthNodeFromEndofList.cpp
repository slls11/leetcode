
class Solution {
    /* Single pass, Runtime: O(n) */
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* middle = head;
        ListNode* front = head;        

        for (int i = 0; i < n; i++) front = front->next;
        
        if (front == nullptr) {
            middle = middle->next;
            return middle;
        }
        
        while (front->next != nullptr){
            front = front->next;
            middle = middle->next;
        } 
        middle->next = middle->next->next;

    return head;
    }
};



class Solution {
/* Double pass, Runtime: O(2n) -> O(n) */ 
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;

        int count = 1;
        while (right->next != nullptr){
            right = right->next;
            count++;
        }

        if (count == n) {
            head = head->next;
            return head;
        }
        
        ListNode* left = head;
        ListNode* middle = head->next;
        for (int i = count; i > n+1; i--){
            left = left->next;
            middle = middle->next;
        }

        if (middle->next == nullptr) middle = nullptr;
        else middle = middle->next;

        left->next = middle;

    return head;
    }
};

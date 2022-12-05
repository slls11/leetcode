class Solution {
    /* move 1 step for every 2 steps solution */
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* middle = head;
        ListNode* end = head;
        while (end != nullptr && end->next != nullptr){
            end = end->next->next;
            middle = middle->next;
        }
    return middle;
    }
};



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* trvs = head;
        int length = 0;  
        while (trvs != nullptr){
            length++;
            trvs = trvs->next;
        }
        
        int mid = length/2; 
        while (mid > 0){
            head = head->next;
            mid--;
        }
        
    return head;
    }
};

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

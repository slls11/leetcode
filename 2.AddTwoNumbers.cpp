class Solution {
 /* Runtime: O(n) */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        short carry = 0;
        ListNode* head = l1;
        while (1){
            short add = l1->val + l2->val + carry;
            if  (add - 9 > 0) {
                add = add - 10;
                carry = 1;
            }
            else carry = 0;

            l1->val = (add);
            if (l1->next != nullptr && l2->next != nullptr){
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }
            else if (l1->next == nullptr && l2->next != nullptr) l1->next = new ListNode(0);
            else if (l1->next != nullptr && l2->next == nullptr) l2->next = new ListNode(0);
            else if (l1->next == nullptr){
                if (carry) l1->next = new ListNode(1);
                break;
            }
            l1 = l1->next;
            l2 = l2->next;  
        }
    return head;
    }
};

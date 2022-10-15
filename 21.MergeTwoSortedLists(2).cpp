class Solution {
public:
    // solution using a new ll, not constant space complexity, iterative solution
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList;
        
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            newList = list1;
            list1 = list1->next;
        }
        else {
            newList = list2;
            list2 = list2->next;
        }
        
        ListNode* head = newList;

        if (list1 == nullptr){
                newList->next = list2;
                return newList;
            }
        else if (list2 == nullptr){
            newList->next = list1;
            return newList;
        }

        while (1){
            if (list1->val <= list2->val){
                newList->next = list1;
                newList = newList->next;
                list1 = list1->next;
            }
            else if (list2->val < list1->val){
                newList->next = list2;
                newList = newList->next;
                list2 = list2->next;
            }
            
            if (list1 == nullptr){
                newList->next = list2;
                return head;
            }
            else if (list2 == nullptr){
                newList->next = list1;
                return head;
            }
        }
        
    return head;
    }
};

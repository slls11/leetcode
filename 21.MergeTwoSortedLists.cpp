class Solution {
public:
    // soving using an extra linked list, not constant space complexity
    // a messy but working solution...
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr){
            return list2;
        }
        else if (list2 == nullptr){
            return list1;
        }
        
        ListNode* mergedList;    
        if (list1->val <= list2->val){
            mergedList = list1;
            list1 = list1->next;
        }
        else{
            mergedList = list2;
            list2 = list2->next;     
        }
        
        ListNode* head = mergedList;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                mergedList->next = list1;
                mergedList = mergedList->next;
                list1 = list1->next;
            }
            else{
                mergedList->next = list2;
                mergedList = mergedList->next;
                list2 = list2->next;     
            }

        }
        
        if (list1 == nullptr && list2 != nullptr){
            mergedList->next = list2;
        }
        else if (list2 == nullptr && list1 != nullptr){
            mergedList->next = list1;
        }
    
    return head;
    }
};

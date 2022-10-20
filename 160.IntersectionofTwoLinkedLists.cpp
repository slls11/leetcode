class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode*, int> map;
        // insert ListNode Address and value in hash map
        while (headA != nullptr){ 
            if (map.find(headA) == map.end()) 
                map[headA] = headA->val;    
            
            headA = headA->next;
        }
        while (headB != nullptr){ 
            if (map.find(headB) == map.end()) 
                map[headB] = headB->val;
            else 
                return headB;
        
            headB = headB->next;
        }
        
    return nullptr;
    }
};

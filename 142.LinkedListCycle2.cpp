class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map <ListNode*,int> map;
        ListNode* copy = head;
        
        if (head == nullptr){
            return nullptr;
        }
        else if (head->next == nullptr){
            return nullptr;
        }
        
        map.insert({head,1});
        while (map.find(head->next) == map.end()){
            map.insert({head->next,1});
            head = head->next;
            
            if (head->next == nullptr){return nullptr;}
        }        
        
        while (copy != nullptr){
            if (copy == head->next){
                return copy;
            }
            else{
                copy = copy->next;
            }
        }

    return nullptr;
    }
};

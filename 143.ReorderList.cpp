class Solution {
/* Runtime: O(n^2) */
public:
    void reorderList(ListNode* head) {
        ListNode* front = head;
        ListNode* middle = head;
        ListNode* back = head;

        while (back->next != nullptr){
            if (back->next->next == nullptr){
                back = back->next;
                middle = middle->next;
            }
            else{
                back = back->next->next;
                middle = middle->next;
            }
        }

        while (middle->next != nullptr){
            ListNode* new_back = middle;
            back = middle->next;

            while (back->next != nullptr){
                back = back->next;
                new_back = new_back->next;
            }
            back->next = front->next;
            front->next = back;
            new_back->next = nullptr;
            front = front->next->next;
        }
    }
};

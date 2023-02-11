class Solution {
/* Runtime: O(n), Space: O(1) */
public:
    ListNode* reverse(ListNode* back){
        ListNode* middle = back->next;
        ListNode* front = middle;

        back->next = nullptr;
        while (middle != nullptr){
            front = front->next;
            middle->next = back;
            back = middle;
            middle = front;
        }
    return back;
    }

    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) return;

        ListNode* middle = head;
        ListNode* back = head;
        while (back->next != nullptr){
            if (back->next->next == nullptr){
                middle = middle->next;
                back = back->next; 
            }
            else{
                middle = middle->next;
                back = back->next->next;
            }
        }
         
        ListNode* right_start = reverse(middle->next);
        middle->next = nullptr;

        ListNode* left_start = head;
        ListNode* new_right_start = right_start;

        while (left_start->next != nullptr){
            if (new_right_start == nullptr) break;
            else new_right_start = new_right_start->next;

            right_start->next = left_start->next;
            left_start->next = right_start;

            left_start = right_start->next;
            right_start = new_right_start;
        }

    }
};




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

class Solution {
  /* tortise and hare solution, Runtime: O(n), Space: O(1) */
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
    return false;
    }
};

class Solution {
    /* comparing memory addresses solution, Runtime: O(n), Space: O(1) */
public:
    bool hasCycle(ListNode *head) {
        size_t prev = 0; 
        while (head != nullptr){
            if (size_t(head) <= prev) return true;
            prev = size_t(head);
            head = head->next;
        }
    return false;
    }
};

class Solution {
    /* memory address hash map solution, Runtime: O(n), Space: O(n) */
public:
    bool hasCycle(ListNode *head) {
        unordered_map<void*,int> map;
        while (head != nullptr){
            if (map.find(head) != map.end()) return true;
            map[head]++;
            head = head->next;
        }
    return false;
    }
};

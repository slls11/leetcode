class Solution {
/* Runtime: O(n), Space: O(1) */
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];  
        fast = nums[fast];
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
    return slow;
    }
};

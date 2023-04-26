class Solution {
  /* Runtime: O(n), Space: O(1) */
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else if (nums.size() == 3) return max(nums[0]+nums[2], nums[1]);

        nums[2] += nums[0];

        for (int i = 3; i < nums.size(); i++) nums[i] += max(nums[i-3], nums[i-2]);
        
    return max(nums[nums.size()-2], nums[nums.size()-1]);
    }
};

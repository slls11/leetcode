class Solution {
  /* Runtime: O(n), Space: O(1), (input vector is not counted toward space) */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        ans[0] = 1;

        for (int i = 1; i < nums.size(); i++) 
            ans[i] = (ans[i-1] * nums[i-1]);
        
        int prev = 1;
        for (int i = nums.size()-1; i > -1; i--){
            ans[i] = ans[i] * prev;
            prev = prev * nums[i];
        }
    return ans;
    }
};

class Solution {
  /* Runtime: O(n^2) */
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        int max_value = 1;
        for (int j = nums.size()-1; j > -1; j--){
            int local_max = 1;
            for (int i = j+1; i < nums.size(); i++){
                if (nums[i] > nums[j]) local_max = max(local_max, dp[i]);
            }
            dp[j] += local_max;
            max_value = max(max_value, dp[j]);
        }

    return max_value-1;
    }
};

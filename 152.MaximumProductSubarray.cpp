class Solution {
  /* Runtime: O(n), Space: O(1) */
public:
    int maxProduct(vector<int>& nums) {
        int real_max = nums[0];
        pair<int,int> values = {nums[0], nums[0]};
        
        for (int i = 1; i < nums.size(); i++){
            int min_val = nums[i] * min(nums[i-1], min(values.first, values.second));
            int max_val = nums[i] * max(nums[i-1], max(values.first, values.second));

            values.first = min_val;
            values.second = max_val;

            real_max = max(real_max, max(nums[i], max(min_val, max_val)));
        }

    return real_max;
    }
};

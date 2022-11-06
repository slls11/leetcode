class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int real_max = nums[0], local_max = 0;
        for (int i = 0; i < nums.size(); i++){
            local_max += nums[i];
          
            if (local_max > real_max) real_max = local_max;
          
            if (local_max < 0) local_max = 0;
        }
    return real_max;
    }
};

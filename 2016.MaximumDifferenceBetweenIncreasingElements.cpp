class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN, diff = -1, max_diff = -1;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] <= min) {
                min = nums[i];
                max = INT_MIN;
                diff = -1;
            }
            else if (nums[i] > max) {
                max = nums[i];
                diff = max - min;
            }
            
            if (diff > max_diff) max_diff = diff;
        }
        
    return max_diff;
    }
};

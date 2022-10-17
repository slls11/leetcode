class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currentTotal = 0;
        
        for (int i = 0; i < nums.size(); i++){
            currentTotal = currentTotal + nums[i];
            nums[i] = currentTotal;
        }
        
    return nums;
    }
};

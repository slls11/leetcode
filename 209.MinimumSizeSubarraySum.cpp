class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = INT_MAX;
        int back = 0, front = 0, total = nums[0];
        while (front < nums.size() && back < nums.size()){
            if (total >= target){
                if (back < nums.size()) {
                    if ((front - back) < min_length) min_length = (front - back);
                    total -= nums[back];
                }
                back++;
            }
            else{
                front++;
                if (front < nums.size()) total += nums[front];
            }
        }
    
        if (min_length == INT_MAX) return 0;
        else if (min_length == 0) return 1;
        
    return min_length + 1;
    }
};

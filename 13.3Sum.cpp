class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1, right = nums.size()-1;
            while (left < right){
                if (left > i+1 && nums[left] == nums[left-1]){
                    left++;
                    continue;
                }

                int value = nums[i] + nums[left] + nums[right];
                if (value == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                }
                else if (value > 0) right--;
                else if (value < 0) left++;
            }
        }
    return ans;
    }
};

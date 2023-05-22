class Solution {
  /* DP */
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) return false;
        target /= 2;

        unordered_set<int> dp;
        dp.insert(0);

        for (int i = 0; i < nums.size(); i++){
            unordered_set<int> next_dp;
            for (auto it = dp.begin(); it != dp.end(); it++){
                if (*it + nums[i] == target) return true;
                next_dp.insert(*it + nums[i]);
                next_dp.insert(*it);
            }
            dp = next_dp;
        }
    return false;
    }

};



class Solution {
  /* Brute Force */
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) return false;
        target /= 2;

    return dfs(nums, target, 0);
    }

    bool dfs(vector<int>& nums, int target, int pos){
        if (target < 0 || pos >= nums.size()) return false;
        if (target - nums[pos] == 0) return true;

    return  (dfs(nums, target-nums[pos], pos+1) || dfs(nums, target, pos+1));
    }
};

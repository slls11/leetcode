class Solution {
  /* Runtime: O(n * 2^n) */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        dps(ans, sub, nums, 0);
    return ans;
    }

    void dps(vector<vector<int>>& ans, vector<int>& sub, vector<int>& nums, int start){
        ans.push_back(sub);

        for (int i = start; i < nums.size(); i++){
            sub.push_back(nums[i]);
            dps(ans, sub, nums, i+1);
            sub.pop_back();
        }
    }
};

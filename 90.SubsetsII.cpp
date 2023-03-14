class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, ans, curr, 0);
    return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int start){
        ans.push_back(curr);
        for (int i = start; i < nums.size(); i++){
            if (i > start && nums[i-1] == nums[i]) continue;
            curr.push_back(nums[i]);
            dfs(nums, ans, curr, i+1);
            curr.pop_back();
        }
    }
};

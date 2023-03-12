class Solution {
  /* Brute Force, not optimal */
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int,int> map;
        dfs(nums, ans, curr, map, 0);
    return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, unordered_map<int,int> map, int start){
        if (map.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); i++){
            if (map.find(nums[i]) != map.end()) continue;

            curr.push_back(nums[i]);
            map[nums[i]]++;

            dfs(nums, ans, curr, map, 0);

            map.erase(nums[i]);
            curr.pop_back();
        }
    }
};

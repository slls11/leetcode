class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, ans, curr, 0, 0);
    return ans;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curr, int run_total, int start){
        if (run_total == target) {
            ans.push_back(curr);
            return;
        }
        else if (run_total > target) return;

        for (int i = start; i < candidates.size(); i++){
            if (i > start && candidates[i-1] == candidates[i]) continue;
            curr.push_back(candidates[i]);
            dfs(candidates, target, ans, curr, run_total+candidates[i], i+1);
            curr.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        combination(candidates, target, 0, curr);

        vector<vector<int>> ans_clean;
        map<vector<int>,int> map;

        for (auto& iter : ans){
            vector<int> temp(150,0);
            for (auto& iter2 : iter) temp[iter2 - 0]++;

            if (map.find(temp) == map.end()) {
                map.insert({temp,1});
                ans_clean.push_back(iter);
            }
        }

    return ans_clean;
    }

    void combination(vector<int>& candidates, int target, int run_total, vector<int>& curr){
        if (run_total > target) return;
        else if (run_total == target){
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            combination(candidates, target, run_total + candidates[i], curr);
            curr.pop_back();
        }
    }
};

class Solution {
  /* Runtime: O(n), Space: O(n) */
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (auto& it : nums) map[it]++;

        vector<vector<int>> count(nums.size()+1);
        for (auto& it : map) count[it.second].push_back(it.first);

        vector<int> ans;
        for (int i = count.size()-1; k > 0 && i > 0; i--){
            if (count[i].size() > 0){
                for (int j = 0; j < count[i].size(); j++){
                    ans.push_back(count[i][j]);
                    k--;
                }
            }
        }

    return ans;
    }
};          



class Solution {
  /* O(nlog(n)) solution? */
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (auto iter : nums) map[iter]++;

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < nums.size(); i++){
            if (map[nums[i]] > 0){
                pq.push(make_pair(map[nums[i]],nums[i]));
                map[nums[i]] = 0;
            } 
        }

        vector<int> ans(0,k);
        for (int i = k; i > 0; i--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
    return {ans};
    }
};

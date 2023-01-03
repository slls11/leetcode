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

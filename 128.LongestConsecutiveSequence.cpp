class Solution {
  /* O(n) runtime solution */
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int,int> map;
        for (auto& iter : nums) map[iter]++;

        int max = 1, local_max = 1;
        for (auto& iter : nums){
            if (map.find(iter-1) == map.end()){ // if true found start of a series
                for (int i = 1; i < nums.size(); i++){ // looking for consecutive elements in map
                    if (map.find(iter+i) != map.end()) local_max++;
                    else {
                        local_max = 1;
                        break;
                    }
                    if (local_max > max) max = local_max;
                }
            }
        }
    return max;
    }
};

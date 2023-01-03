class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for (auto iter : nums){
            map[iter]++;
            if (map[iter] > 1) return true;
        }
    return false;
    }
};

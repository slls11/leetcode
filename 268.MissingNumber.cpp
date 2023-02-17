class Solution {
  /* Runtime: O(n) */
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size()+1; i++) sum += i;
        for (auto& iter : nums) sum -= iter;
    return sum;
    }
};

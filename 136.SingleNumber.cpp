class Solution {
  /* use XOR bit */
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& iter : nums) ans = (ans ^ iter);
    return ans;
    }
};

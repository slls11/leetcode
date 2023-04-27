class Solution {
public:
  /* Runtime: O(n), Space O(n) */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else if (nums.size() == 3) return max(nums[1], max(nums[0], nums[2]));

        int sec_one = count_amount(nums, 0, nums.size()-2);
        int sec_two = count_amount(nums, 1, nums.size()-1);

    return max(sec_one, sec_two);
    }

    int count_amount(vector<int> nums, int start, int end){
        nums[start+2] += nums[start];

        for (int i = start+3; i <= end; i++) 
            nums[i] += max(nums[i-3], nums[i-2]);

    return max(nums[end-1], nums[end]); 
    }
};


/* 

class Solution {
public:
    int rob(vector<int>& nums) {
        

    }
}; */

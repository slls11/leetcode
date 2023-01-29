class Solution {
  /* Runtime: O(log(n)) */
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int mid = right/2;
        while (left < right){

            if (left == mid) {
                if (nums[mid] > nums[mid+1]) return nums[mid+1];
                else return nums[mid];
            }
            else if (nums[mid] < nums[right]){
                right = mid;
                mid = (mid+left)/2;  
            }
            else if (nums[left] < nums[mid]){
                left = mid;
                mid = (right+left)/2;
            }
        }

    return nums[mid];
    }
};

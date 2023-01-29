class Solution {
  /* Runtime: O(log(n)), this can be compacted but it is easier to look at with all 5 cases explicitly written out */
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = right/2;
        while (left <= right){

            if (nums[mid] == target) 
                return mid;
            else if (nums[mid] > nums[right] && target <= nums[right]){
                left = mid + 1;
                mid = (right+left)/2;
            }
            else if ((nums[mid] < nums[right]) && (target >= nums[mid] && target <= nums[right])){
                left = mid + 1;
                mid = (right+left)/2;
            }
            else if (nums[mid] < target && nums[mid] > nums[right]){
                left = mid + 1;
                mid = (right+left)/2;
            }
            else{
                right = mid - 1;
                mid = (right+left)/2;
            }
        }

    return -1;
    }
};

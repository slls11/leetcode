class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
    return quick_select(nums, 0, nums.size()-1, index);
    }

    int quick_select(vector<int>& nums, int left, int right, int index){
        int pos = left;
        int pivot = right;
        for (int i = left; i < right; i++){
            if (nums[i] <= nums[pivot]){
                swap(nums[i], nums[pos]);
                pos++;
            }
        }

        swap(nums[pos], nums[pivot]);
        if (index < pos) return quick_select(nums, left, pos-1, index);
        else if (index > pos) return quick_select(nums, pos+1, right, index);

    return nums[pos];
    }
};

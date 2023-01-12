class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (left < right){
            int value = target - (numbers[left] + numbers[right]);
            if (value == 0) return {left+1, right+1};
            else if (value < 0) right--;
            else if (value > 0) left++;
        }
    return {};
    }
};

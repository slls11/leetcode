class Solution {
  /* O(n) solution */
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, left = 0, right = height.size()-1;
        while (left < right){
            int width = right - left;
            int length = min(height[left], height[right]);
            
            if ((length * width) > max_area) max_area = (length * width);

            if (height[left] <= height[right]) left++;
            else if (height[left] > height[right]) right--;
        }
    return max_area;
    }
};

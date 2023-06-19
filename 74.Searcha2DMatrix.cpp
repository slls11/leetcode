class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& it : matrix){
            if (target > it.back()) continue;
            return binary_search(it, target);
        }
    return false;
    }

    bool binary_search(vector<int>& vec, int target){
        int low = 0, high = vec.size()-1, mid = high/2;
        while (low <= high){
            if (vec[mid] == target) return true;
            else if (vec[mid] < target) low = mid + 1;
            else high = mid - 1;
            mid = (high+low)/2;
        }
    return false;
    }
};




class Solution {
public:
    bool binary_search(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int mid = high/2;
        while (low <= high){
            if (nums[mid] == target) return true;
            else if (nums[mid] < target){
                low = mid + 1;
                mid = (high+low)/2;
            }
            else if (nums[mid] > target){
                high = mid - 1;
                mid = high/2;
            }
        } 
    return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 1) return binary_search(matrix[0], target);

        for (int i = 1; i < matrix.size(); i++){
            if (target < matrix[i][0]) return binary_search(matrix[i-1], target);
        }
        return binary_search(matrix[matrix.size()-1], target);
    return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++){
            if (target >= matrix[i][0] && (i == matrix.size()-1 || target < matrix[i+1][0])){
                for (int j = 0; j < matrix[0].size(); j++){
                    if (target == matrix[i][j]) return true;
                }
            }
        }
    return false;
    }
};

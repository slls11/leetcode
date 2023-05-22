class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int s = matrix.size();
       for (int i = 0; i < s; i++){
           for (int j = i; j < s; j++) swap(matrix[i][j], matrix[j][i]);
        reverse(matrix[i].begin(), matrix[i].end());
       } 
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_colum = false, first_row = false;
        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[0][j] == 0) first_colum = true;
        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0) first_row = true;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[0][j] == 0) set_zero_row(matrix, j);
        for (int i = 1; i < matrix.size(); i++)
            if (matrix[i][0] == 0) set_zero_col(matrix, i);

        if (first_colum)
            for (int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        if (first_row)
            for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }

    void set_zero_row(vector<vector<int>>& matrix, int r){
        for (int i = 0; i < matrix.size(); i++) matrix[i][r] = 0;
    }
    void set_zero_col(vector<vector<int>>& matrix, int c){
        for (int j = 0; j < matrix[0].size(); j++) matrix[c][j] = 0;
    }

};

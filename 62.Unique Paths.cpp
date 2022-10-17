class Solution {
public:
    // Runtime: O(m*n)
    int uniquePaths(int m, int n){
        // m+1,n+1 added so that 0 added to grid element when accessing outside the m*n grid
        vector <vector<int>> grid(m+1, vector<int>(n+1, 0)); 
        grid[m-1][n-1] = 1;
        
        for (int i = m-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--){
                grid[i][j] += grid[i+1][j] + grid[i][j+1];
            }
        }
        
    return grid[0][0];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                int local_max = 0;
                if (grid[i][j] == 1) search(grid, local_max, i, j);
                if (local_max > max) max = local_max;
            }
        }
    return max;
    }

    void search(vector<vector<int>>& grid, int& local_max, int i, int j){
        if (i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1 || grid[i][j] == 0)
            return;

        local_max++;
        grid[i][j] = 0;

        search(grid, local_max, i-1, j);
        search(grid, local_max, i+1, j);
        search(grid, local_max, i, j-1);
        search(grid, local_max, i, j+1);
    return;
    }
};

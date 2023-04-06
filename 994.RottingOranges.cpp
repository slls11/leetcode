class Solution {
  /* Runtime: O(n*m), linear */
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2) rotten.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        
        int min = 0;
        while (fresh > 0){

            int rotten_pre_add = rotten.size();
            while (rotten_pre_add > 0){
                bfs(grid, rotten, fresh);
                rotten_pre_add--;
            }

            min++;
            if (rotten.size() == 0 && fresh > 0) return -1;
        }
    return min;
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& rotten, int& fresh){
        int i = rotten.front().first, j = rotten.front().second;
        rotten.pop();

        if (i > 0){ 
            if (grid[i-1][j] == 1) {
                rotten.push({i-1,j});
                grid[i-1][j] = 2;
                fresh--;
            }
        }
        if (i < grid.size()-1){
            if (grid[i+1][j] == 1) {
                rotten.push({i+1,j});
                grid[i+1][j] = 2;
                fresh--;
            }
        }
        if (j > 0){ 
            if (grid[i][j-1] == 1) {
                rotten.push({i,j-1});
                grid[i][j-1] = 2;
                fresh--;
            }
        }
        if (j < grid[0].size()-1){
            if (grid[i][j+1] == 1) {
                rotten.push({i,j+1});
                grid[i][j+1] = 2;
                fresh--;
            }
        }
    }

};

class Solution {
public:
    int count = 0;
    
    void fullIsland(vector<vector<char>> &grid, int x, int y){  
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') return;
        
        grid[x][y] = '3';
        fullIsland(grid, x+1, y);
        fullIsland(grid, x-1, y);
        fullIsland(grid, x, y+1);
        fullIsland(grid, x, y-1);
    }  
        
   void search(vector<vector<char>> &grid, int x, int y){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '2') return; // cord outside grid or marked     
        
        if (grid[x][y] == '0' || grid[x][y] == '3') grid[x][y] = '2';
       
        else if (grid[x][y] == '1'){ //found some part or whole island
            count++;
            fullIsland(grid, x, y);
        }
        search(grid, x+1, y);
        search(grid, x-1, y);
        search(grid, x, y+1);
        search(grid, x, y-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        search(grid, 0, 0);
    return count;
    }
};

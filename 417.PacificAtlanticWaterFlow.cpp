class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size()));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size()));

        for (int i = 0; i < heights.size(); i++){
            dfs(heights, pacific, i , 0);
            dfs(heights, atlantic, i , heights[0].size()-1);
        }
        for (int j = 0; j < heights[0].size(); j++){
            dfs(heights, pacific, 0 , j);
            dfs(heights, atlantic, heights.size()-1, j);
        }

        for (int i = 0; i < heights.size(); i++){
            for (int j = 0; j < heights[0].size(); j++){
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }

    return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& record, int i, int j){
        record[i][j] = true;

        if (i > 0 && !(record[i-1][j]) && heights[i-1][j] >= heights[i][j]) 
            dfs(heights, record, i-1, j);
        if (i < heights.size()-1 && !(record[i+1][j]) && heights[i+1][j] >= heights[i][j]) 
            dfs(heights, record, i+1, j);
        if (j > 0 && !(record[i][j-1]) && heights[i][j-1] >= heights[i][j]) 
            dfs(heights, record, i, j-1);
        if (j < heights[0].size()-1 && !(record[i][j+1]) && heights[i][j+1] >= heights[i][j]) 
            dfs(heights, record, i, j+1);
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color){
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], color);
    return image;
    }
    
    void dfs(vector<vector<int>> &image, int x, int y, int oldColor, int newColor){
        if (x < 0 || x >= image.size() || y < 0 || y >= image[1].size() || image[x][y] != oldColor){
            return;
        }
        image[x][y] = newColor;
        dfs(image, x-1, y, oldColor, newColor);
        dfs(image, x+1, y, oldColor, newColor);
        dfs(image, x, y-1, oldColor, newColor);
        dfs(image, x, y+1, oldColor, newColor);
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> col(9), row(9), block(9);
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                char chr = board[i][j];
                if (chr == '.') continue;
                int num_block = ((j/3)*3)+i/3;
                if (col[i].count(chr) || row[j].count(chr) || block[num_block].count(chr))
                    return false;
                
                col[i].insert(chr); row[j].insert(chr); block[num_block].insert(chr);
            }
        }
    return true;
    }
};

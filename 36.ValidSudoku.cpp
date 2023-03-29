class Solution {
public:
    /* Runtime: O(m*n) */
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



class Solution {
public:
/* kinda dumb but works O(3*(n*m)) -> O(n*m), linear */
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++){
            vector<int> count(10,0);
            for (int j = 0; j < board[0].size(); j++){
                char val = board[i][j];
                if (val != '.'){
                    count[val - '0']++;
                    if (count[val - '0'] > 1) return false;
                }
                
            }
        }
        for (int i = 0; i < board.size(); i++){
            vector<int> count(10,0);
            for (int j = 0; j < board[0].size(); j++){
                char val = board[j][i];
                if (val != '.'){
                    count[val - '0']++;
                    if (count[val - '0'] > 1) return false;
                }
            }
        }
        for (int x = 0; x < board.size()-2; x+=3){
            for (int y = 0; y < board[0].size()-2; y+=3){
                vector<int> count(10,0);
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        char val = board[x+i][y+j];
                        if (val != '.'){
                            count[val - '0']++;
                            if (count[val - '0'] > 1) return false;
                        }
                        
                    }
                }


            }
        }
    return true;
    }
};

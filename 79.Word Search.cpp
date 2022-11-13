class Solution {
public:
    bool sub_search(vector<vector<char>>& board, int i, int j, string word, int num_matched){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[num_matched])
            return false;
        else if (num_matched == word.length() - 1) return true;
        else {
          char chr = board[i][j]; board[i][j] = '*';
          num_matched++;
          if (sub_search(board, i-1, j, word, num_matched)) return true;
          if (sub_search(board, i+1, j, word, num_matched)) return true;
          if (sub_search(board, i, j-1, word, num_matched)) return true;
          if (sub_search(board, i, j+1, word, num_matched)) return true;
          board[i][j] = chr;
        }
    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (sub_search(board, i, j, word, 0)) return true;                    
                }
            }
        }
    return false;
    }
};

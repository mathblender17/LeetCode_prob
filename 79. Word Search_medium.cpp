class Solution {
public:
/**
CORE IDEA:use the 2d vector to traveese - originally i used hash set but the time limit exceed so 
then shited to chage teh the char in the 2d vector to '#' and when backtracking make it back to the origianl character
this was the tie cmoplexity stills remins the same but the time limit excedd does not occur 
**/
    int row;
    int col;
    //set<pair<int, int>> path;
     bool exist(vector<vector<char>>& board, string word) {
        // bool ans;
        row = board.size();
        col = board[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.length()) {
            return true;
        }
        if (r < 0 || r >= row || c < 0 || c >= col || board[r][c] != word[i]) {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        //path.insert({r, c});
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        //path.erase({r, c});
         board[r][c] = temp;
        return res;
    }
};

class Solution {
public:
/**
Core idea: logically the problem is easy to understand - place N queens on a NxN board such that no queen is in conflicting position
- to do this we take the help of recursion + backtracling 
- Now the way to implemt this is the most important - to do recusive calls and bactrack when you reach the end or no possible position is left for the the queen to be safely placed
- we go from top row by row as each row should have only 1 queen - and while going down the rows check for the columns , then main diagonal(l->r  down) and then anti diagonal(l->r  up) ( note;-Here we don't check the ones below as we have yet to make their placement aslso this way less things to check)
- then we go through all the positions n the row - checking for positons of conflicts - if no conlfict then we place queen and give recusive call to the next row
- if no free posotion is found we backtrack and continue checking with other position in the previous row
**/
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;//final result
        vector<string> board(n,string(n,'.')); //to strore the Q positions each row
        backtrack(0,board,res);
        return res;
    }
    void backtrack(int r,vector<string>& board,vector<vector<string>>& res){
        //base case
        if(r==board.size()){
            res.push_back(board);
            return ;
        }
        
        // r is the rows
        for(int c=0;c<board.size();c++){
            if(ifValid(r,c,board)){
                board[r][c]='Q';//Q placement picked
                backtrack(r+1,board,res);//recursive call
                board[r][c]='.';//kinda like poping but just overwitten     
            }
        }

    }
    bool ifValid(int r,int c,vector<string>& board){
        for(int i=r-1;i>=0;i--){ //checking in the column
            if(board[i][c]=='Q')return false;
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){ //checking the main diagonal
            if(board[i][j]=='Q')return false;
        }
        for(int i=r-1,j=c+1;i>=0 && j<board.size();i--,j++){ //checking the anti diagonal
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
};

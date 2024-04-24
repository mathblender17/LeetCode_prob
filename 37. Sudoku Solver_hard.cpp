class Solution {
public:
/**
too little help
**/ 
    bool isValid(int i,int j , char c, vector<vector<char>>& board){
        for(int k=0;k<9;k++){
            //checking rows
            if(board[i][k] == c)return false;
            //checking coluns
            if(board[k][j] == c)return false;
            //checking in 3X3 grid
            // i/3 and j/3  fone to find the start row and column of each element then muliply by 3
            // to iterate over each the row k%3   and to iterate each column k-3
            if( board[3*(i/3)+(k/3)] [3*(j/3)+(k%3)] == c)return false;
        }
        return true; // all conditions are true;

    }

    bool solve(vector<vector<char>>& board){
       //to traverse through the board
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
            //finding the empty spot
               if(board[i][j] == '.'){
                //Trying the all 1-9 in that position
                for(char c='1';c<='9';c++){
                    if(isValid(i,j,c,board)){
                        board[i][j] = c;//if corect update in the board
                        if(solve(board))return true;// then recurse
                        board[i][j] ='.';//backtracks and chages the board if other combinations are not working 
                    }
                }
                return false;//could not find a number to place in the mepty space - no solution for this "." for that position
               }
                
            }
        }
        return true;
    }

   
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

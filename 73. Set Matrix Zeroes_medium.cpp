class Solution {
public:
/**
CORE IDEA: all the rows and columns where we get 0 set it all to 0
brute force - traverse the matrix to find 0's the matrix then 
to change the rows and columns  to 0 except the ones where ) already exists
TC - O((N*M)(N+M)) Space O(1)- traversasl and one for changing the converted rows and columsn

Optimal :- 
TC - O(2*(N*M)+O(N+M)) space O(1) - we  use a row andd column array (oth of both )
to keeep the track of the rows and the coluns to be removed 
**/
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col=1;//ofr the oth column
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col=0;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }if(col==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }

        
    }
};

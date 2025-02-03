class Solution {
public:
/**
CORE idea :- we use bfs to traverse all the nodes in 4directions
main bfs technoque still remains the same ;- use queue to traverse
1-> to know how many fresh are present - we need to chage all of them
2-> we nned to know the positions of 2's for rotten - work as root nodes
use time and fresh to keep track of time spent and fresh fruit count
 use dir array for 4 diretinal traversal
 while for main condition to check if the queue and the fresh is empthy
 1st for loop for to take a look at the q.front() of the 2's(position dtored in queue)
 2ns for loop for the 4d travel
 "if" for checking the main conditon '==1' nad edge cases 
    if true chage to =2 and add in the queue nad fresh--
  after the 1st for loop and befre the while loop do time++ shows the changes made after one traversal
lastly check if all the fresh==0 if true return time else return -1

TC:- O(m*n)  SC:- O(m*n)
**/
    int orangesRotting(vector<vector<int>>& grid) {
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int R = grid.size();
        int C = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while (fresh > 0 && !q.empty()) {
            int len=q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;
                for(int j=0;j<4;j++){
                    int nr=r+dir[j][0];
                    int nc=c+dir[j][1];
                    if(nr>=0 && nr<grid.size() &&
                    nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                    }

                }
            }
            time++;
        }
        return fresh==0 ? time : -1;
    }
};

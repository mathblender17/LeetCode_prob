class Solution {
public:
    /**
    just like 200th question
    traverese the matrix in a bfs manner while chwcking all the 4 directions 
    for the area count all the inputs given in the queue for a island and keep the max island value with you 
    **/
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, bfs(grid, r, c));
                }
            }
        }
        return maxArea;
    }
    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        int a = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    a++;
                }
            }
            
        }
        return a;
    }
    };

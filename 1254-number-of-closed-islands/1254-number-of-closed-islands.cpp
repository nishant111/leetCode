class Solution {
public:
    vector<pair<int,int>> d={{0, -1},{-1,0},{0,1},{1,0}};
    bool dfs(vector<vector<int>> &grid, int r, int c, vector<vector<bool>>& visit) {
        
        if(r == 0 || r == grid.size()-1 ||
            c == 0 || c == grid[0].size()-1)
            {
                return false;
            }
        visit[r][c] = 1;
         bool isClosed = true;
        for(auto elem:d){
            if(grid[r+elem.first][c+elem.second] == 0 && !visit[r+elem.first][c+elem.second]) {
                if(!dfs(grid, r+elem.first, c+elem.second, visit) )
                {
                      isClosed = false;
                }
            }
        }
        return isClosed;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 0 && !visit[i][j])
                {
                    if(dfs(grid, i, j, visit))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
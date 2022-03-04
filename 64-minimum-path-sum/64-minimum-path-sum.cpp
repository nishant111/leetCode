class Solution {
public:
    int dfs(vector<vector<int>> & grid, int x, int y, vector<vector<int>>& dp)
    {
        if(x == grid.size()-1 && y == grid[0].size()-1)
        {
            //reached target
            return grid[x][y];
        }
        if(dp[x][y]!=-1) return dp[x][y];
        int right = INT_MAX;
        int down = INT_MAX;
        if(y+1<grid[0].size())
             right = grid[x][y] + dfs(grid,x, y+1, dp);
        if(x+1<grid.size())
             down = grid[x][y] + dfs(grid, x+1, y, dp);
        
        return dp[x][y] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return dfs(grid, 0, 0, dp);
    }
};
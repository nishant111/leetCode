class Solution {
public:
    int dfs(vector<vector<int>>& grid, int currR, int currC, vector<vector<int>>& dp) {
        if(currR == grid.size()-1 && currC == grid[0].size()-1)
        {
            return grid[currR][currC];
        }
        if(dp[currR][currC] != -1) return dp[currR][currC];
        int ans = INT_MAX;
        //try down
        int down = INT_MAX;
        int right = INT_MAX;
        if(currR + 1<grid.size())
            down =  (grid[currR][currC] + dfs(grid, currR+1, currC, dp)) ;
        //try right
        if(currC + 1 < grid[0].size())
            right =  ( grid[currR][currC] + dfs(grid, currR, currC + 1, dp) );
        return dp[currR][currC] = min(down, right);

    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(grid, 0, 0, dp);
    }
};
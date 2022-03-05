class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& dp)
    {
        if(row<0 || col < 0) return 0;
        if((row>=0 && col>=0) && obstacleGrid[row][col]==1) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = dfs(obstacleGrid, row-1, col, dp);
        int left = dfs(obstacleGrid, row, col-1, dp);
        return dp[row][col] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return (dfs(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1, dp) );
    }
};
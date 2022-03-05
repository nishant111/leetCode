class Solution {
public:
    int dfs(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp)
    {
        if(row == triangle.size()-1) return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int down = triangle[row][col] + dfs(triangle, row+1,col,dp);
        int diag = triangle[row][col] + dfs(triangle, row+1,col+1,dp);
        return dp[row][col]= min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return dfs(triangle, 0 , 0,dp);   
    }
};
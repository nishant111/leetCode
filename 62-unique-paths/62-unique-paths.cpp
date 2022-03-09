class Solution {
public:
    int dfs(int m, int n, int row, int col, vector<vector<int>> &dp)
    {
        if(row>=m || col >= n) return 0;
        if(row ==m-1 && col == n-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int right = dfs(m, n, row, col+1, dp);
        int down = dfs(m, n, row+1, col, dp);
        return dp[row][col] = right + down;
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return dfs(m, n, 0, 0, dp);
    }
};




/*
class Solution {
public:
    int dfs(int m , int n, int row, int col, vector<vector<int>>& dp)
    {
        if(row >= m ||col >= n) return 0; //not valid
        if(row == m-1 && col == n-1) return 1; //valid path
        if(dp[row][col]!=-1) return dp[row][col];
        int down = dfs(m,n, row+1,col, dp);
        int right = dfs(m,n, row, col+1, dp);
        return dp[row][col] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return dfs(m,n,0,0, dp);
    }
};
*/
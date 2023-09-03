class Solution {
public:
    int dfs(int r, int c, int m, int n, vector<vector<int>> &dp){
        if(r<0 || r==m || c<0 || c==n){
            return 0;
        }
        if (r==(m-1) && c == (n-1)){
            //reached dest
            return 1;
        }
        if(dp[r][c] != -1) return dp[r][c] ;
        int ways = 0;
        //go right
        ways += dfs(r, c+1, m, n, dp);
            
        //go down
        ways += dfs(r+1, c, m, n, dp);
            
        return dp[r][c] = ways;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, dp);
    }
};
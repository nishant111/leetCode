class Solution {
public:
    int mod = 1e9;
    vector<vector<int>> moves = {{0, -1},{-1, 0},{0, 1},{1, 0}};
    int dfs(int m, int n, int maxMove, int cr, int cc, vector<vector<vector<int>>>& dp){
        if(cr < 0 || cr >= m || cc < 0 || cc >= n){
            // found one way dont try beyond this
            return 1;
        }
        if(maxMove == 0){
            // cant go anywhere now
            return 0;           
        }
        if(dp[cr][cc][maxMove]!=-1) return dp[cr][cc][maxMove];
        long long ways = 0;
        for(auto nextMove: moves){
            ways += (dfs(m,n,maxMove-1,cr+nextMove[0],cc+nextMove[1], dp));
        }
        return dp[cr][cc][maxMove]=ways%1000000007;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dfs(m,n,maxMove, startRow, startColumn, dp);
    }
};
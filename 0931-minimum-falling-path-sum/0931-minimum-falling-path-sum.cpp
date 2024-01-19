class Solution {
public:
    vector<vector<int>> dir = {{1,-1},{1, 0},{1,1}};
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>> &dp){
        if(r==matrix.size()-1){
            return matrix[r][c];
        }
        if(dp[r][c]!=INT_MIN) return dp[r][c];
        int sum = INT_MAX;
        int ans = INT_MAX;
        for(auto elem:dir){
            int nr = r + elem[0];
            int nc = c + elem[1];
            if(nc>=0 && nc<matrix[0].size()){
                sum = matrix[r][c] + dfs(matrix, nr, nc, dp);
                //cout<<"sum is "<<sum<<"\n";
            }
            ans = min(ans, sum);
            //cout<<"ans in dfs is "<<ans<<"\n";
        }
        return dp[r][c] = ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MIN) );
        for(int i = 0;i<matrix[0].size();i++){
            //cout<<"calling dfs for "<<matrix[0][i]<<"\n";
            ans = min(ans, dfs(matrix, 0, i, dp));
            //cout<<"ans is "<<ans<<"\n";
        }
        return ans;
    }
};
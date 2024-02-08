class Solution {
public:
    int dfs(int n, vector<int>& dp){
        if(n==1)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int count = INT_MAX;
        int ans = INT_MAX;
        int currSum = 0;
        for(int i = n;i>=1;i--){
            currSum = i*i;
            if(currSum<=n){
                count = 1 + dfs(n-currSum, dp);
            }
            ans = min(ans, count);
        }
        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return dfs(n, dp);
    }
};
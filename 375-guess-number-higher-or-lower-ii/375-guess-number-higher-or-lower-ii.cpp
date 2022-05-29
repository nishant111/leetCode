class Solution {
public:
    
    int dfs(int l, int r, vector<vector<int>> &dp)
    {
        if(l>=r)
            return  0;
        if(dp[l][r]!= 0) return dp[l][r];
        int ans = INT_MAX;
        for(int i = l;i<=r;i++)
        {
            int left = dfs(l, i-1, dp) + i;
            int right = dfs(i+1, r, dp) + i;
            int cash = max(left, right);
            ans = min(ans , cash);
        }
        
        return dp[l][r] = ans;
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        if(n == 1) return 0;
        return dfs(0,n, dp);
    }
};
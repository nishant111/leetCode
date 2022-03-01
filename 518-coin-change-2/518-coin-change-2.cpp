class Solution {
public:
    int dfs(int amount, int curr, vector<int> & coins, int count,
            vector<vector<int>> &dp)
    {
        if(amount < 0 || curr == coins.size()) return 0;
        if(amount == 0) return 1;
        if(dp[amount][curr]!=-1) return dp[amount][curr];
        int pick = dfs(amount - coins[curr], curr, coins, count, dp);
        int nonpick = dfs(amount, curr+1, coins, count,dp);
        return dp[amount][curr] = pick + nonpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        return dfs(amount, 0, coins, 0, dp);
    }
};
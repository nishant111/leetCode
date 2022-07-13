class Solution {
public:
    int dfs(int curr, vector<int> &cost, vector<int> &dp)
    {
        if(curr == cost.size() || curr == cost.size()+1)
        {
            return dp[curr]=0;
        }
        if(dp[curr]!=-1) return dp[curr];
        int ans = 0;
        ans = cost[curr] + min(dfs(curr+1, cost, dp),dfs(curr+2, cost, dp) );
        return dp[curr] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2, -1);
        return min(dfs(0, cost, dp), dfs(1, cost, dp));
    }
};
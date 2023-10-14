class Solution {
public:
    int dfs(int curr, int remain, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if(remain <= 0)
            return 0;
        if(curr >= cost.size())
        {
            //reached end without remain being 0
            return 1e9;
        }
        if(dp[curr][remain]!=-1) return dp[curr][remain];
        int paint = cost[curr] + dfs(curr+1,remain - (1 + time[curr]), cost, time, dp );
        int dontpaint = dfs(curr+1, remain, cost, time, dp);
        return dp[curr][remain] = min(paint, dontpaint);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size()+1, vector<int>(cost.size()+1, -1));
        return dfs(0, cost.size(), cost, time, dp); 
    }
};
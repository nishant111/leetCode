class Solution {
public:
    int dfs(int curr, vector<int> adj[], vector<int>& time, vector<int>& dp){
        if(dp[curr]!=-1) return dp[curr];
        int ans = 0;
        for(auto ngb:adj[curr]){
            ans = max(ans, dfs(ngb, adj, time, dp));
        }
        return dp[curr] = ans + time[curr-1];
    }
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n+1];
        for(auto elem:relations){
            adj[elem[1]].push_back(elem[0]);
        }
        vector<int> dp(n+1, -1);
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            ans = max(ans, dfs(i, adj, time, dp));
        }
        return ans;
    }
};
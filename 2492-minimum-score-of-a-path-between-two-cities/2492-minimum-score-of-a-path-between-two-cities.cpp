class Solution {
public:
    int dfs(int curr, vector<int> &vis, vector<pair<int,int>> adj[], int n) {
        if(vis[curr]) {
            return INT_MAX;
        }
        vis[curr] = 1;
        int ans = INT_MAX;
        for(auto elem:adj[curr]) {
            int ret = min (dfs(elem.first, vis, adj, n),
                        elem.second);
            ans = min(ret, ans);
            
        }
        return ans;

    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        vector<int> vis(n+1, 0);
        for(auto elem:roads) {
            adj[elem[0]].push_back({elem[1],elem[2]});
            adj[elem[1]].push_back({elem[0], elem[2]});
        }
        return dfs(1, vis, adj, n);
    }
};
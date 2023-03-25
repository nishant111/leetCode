class Solution {
public:
    void dfs(vector<int> adj[], int curr, vector<bool> & vis, int &nodesVisited) {
        vis[curr]=1;
        nodesVisited++;
        for(auto elem:adj[curr]) {
            if(vis[elem] == false)
            {
                dfs(adj, elem, vis, nodesVisited);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, 0);
        vector<int> adj[n];
        for(auto elem:edges) {
            adj[elem[0]].push_back(elem[1]);
            adj[elem[1]].push_back(elem[0]);
        }
        int nodesToVis = n;
        int nodesVisited = 0;
        long long ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(vis[i] == false) {
                dfs(adj, i, vis, nodesVisited);
                ans += 1LL * nodesVisited * (nodesToVis-nodesVisited);
                nodesToVis = nodesToVis-nodesVisited;
                nodesVisited = 0;
            }
        }
        return ans;
    }
};
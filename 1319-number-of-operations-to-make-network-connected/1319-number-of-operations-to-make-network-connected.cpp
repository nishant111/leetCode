class Solution {
public:
    void dfs(vector<int> adj[], int curr, vector<bool> &vis) {
        vis[curr] = true;
        for(auto elem:adj[curr]) {
            if(!vis[elem]) {
                dfs(adj, elem, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto elem:connections) {
            adj[elem[0]].push_back(elem[1]);
            adj[elem[1]].push_back(elem[0]);
        }
        vector<bool> vis(n,0);
        int components = 0;
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                components++;
                dfs(adj, i, vis);
            }
        }

        if(connections.size()>=n-1)
        {
            // need atleast 3 cables to connect 4 comp
            return components-1;
        }
        return -1;
    }
};
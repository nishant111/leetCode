class Solution {
public:
    void dfs(vector<pair<int,char>> adj[], int curr, vector<bool> &vis, int &count) {
        vis[curr] = true;
        for(auto elem:adj[curr]) {
            if(!vis[elem.first] && elem.second == 'O'){
                count++;
            }
            if(!vis[elem.first])
                dfs(adj, elem.first, vis, count);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,char>> adj[n];
        for(auto elem:connections) {
            adj[elem[0]].push_back({elem[1], 'O'});
            adj[elem[1]].push_back({elem[0], 'A'});
        }
        vector<bool> vis(n,false);
        int count = 0;
        dfs(adj, 0, vis, count);
        return count;
    }
};
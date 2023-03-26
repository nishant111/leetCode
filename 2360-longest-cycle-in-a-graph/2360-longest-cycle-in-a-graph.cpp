class Solution {
public:
    int ans = -1;
    void dfs( vector<int>& edges, int curr, vector<int> &vis, int currSteps, unordered_map<int ,int> &dist) {
        vis[curr] = 1;
        int nei = edges[curr];

        if(nei != -1 && !vis[nei]){
            dist[nei] = dist[curr]+1;
            dfs(edges, nei, vis, currSteps+1, dist);
        
        }
        else if(nei != -1 && dist.find(nei)!=dist.end()){
            ans = max(ans, dist[curr] - dist[nei] + 1);
        }
        //vis[curr] = -1;
    }
    int longestCycle(vector<int>& edges) {
        vector<int> adj[edges.size()];
        vector<int> vis(edges.size(), false);
        
        
        for(int i = 0;i<edges.size();i++) {
            if(!vis[i]) {
                unordered_map<int ,int> dist;
                dist[i] = 1;
                dfs(edges, i, vis, 0, dist);
                //vis = {-1};
            }
        }
        return ans;
    }
};
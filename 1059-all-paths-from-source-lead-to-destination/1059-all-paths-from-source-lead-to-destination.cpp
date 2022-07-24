class Solution {
public:
    
    bool dfs(int source, int dest, vector<bool> &vis, vector<int> adj[])
    {
        if(source != dest && adj[source].size()==0)
            return false;
        if(vis[source]==true)
            return false;
        vis[source]=true;
        for(auto elem:adj[source])
        {
            bool ret = dfs(elem, dest, vis, adj );
            if(!ret)
                return false;
        }
        vis[source]=false;
        return true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        for(auto elem:edges)
        {
            adj[elem[0]].push_back(elem[1]);
        }
        vector<bool> vis(n, false);
        return dfs(source, destination, vis, adj);
    }
};
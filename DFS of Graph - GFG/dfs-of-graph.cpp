// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(vector<bool> &visited, vector<int> adj[], int i, vector<int> &ans)
    {
        if(visited[i] == true) 
            return;
        visited[i] = true;
        ans.push_back(i);
        for(auto it : adj[i])
        {
            if(visited[it] != true)
            {
                dfs(visited, adj, it, ans);
                visited[it]=true;
            }
        }

    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector <bool> visited (V, false);
        vector<int> ans;
        dfs(visited, adj, 0, ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
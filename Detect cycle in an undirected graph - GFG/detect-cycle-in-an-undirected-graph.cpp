// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkCycleDfs( vector<int> adj[] , vector<bool> &visited, 
                        int i, int parent)
    {
        
        visited[i] = true;
        for(auto it : adj[i])
        {
            if(visited[it] == false)
            {
                if (checkCycleDfs(adj, visited, it, i))
                    return true;
            }
            else if(visited[it] == true && parent!=it)
            {
                return true;
            }

        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        //initialize vector with size V and all value as false
        vector<bool> visited (V, false); 
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                // parent passed initially is invalid
                if(checkCycleDfs(adj, visited ,i, -1))
                    return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
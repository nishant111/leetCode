// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void topoSortBfs(int V, vector<int> adj[], vector<int> &topo)
	{
	    vector <int> indegree(V, 0);
	    for(int i = 0;i<V;i++)
	    {
	        for(auto it: adj[i])
	            indegree[it]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0;i<V;i++)
	    {
	        //cout <<i <<" indegree is "<<indegree[i] << "\n";
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(q.empty()!=true)
	    {
	        int curr = q.front();
	        q.pop();
	        topo.push_back(curr);
	        for(auto it : adj[curr])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
	}
	
	void topoSortDfs(vector<int> adj[], vector<bool> &visited, 
	                 stack<int> &st, int curr)
	{
	    visited[curr] = true;
	    for(auto it:adj[curr])
	    {
	        if(visited[it]!=true)
	            topoSortDfs(adj, visited, st, it);
	    }
	    st.push(curr);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo;
	    //topoSortBfs(V, adj, topo);
	    vector<bool> visited(V, false);
	    stack<int> st;
	    for(int i = 0;i<V;i++)
	    {
	        if(visited[i]!=true)
	        {
	            topoSortDfs(adj, visited, st, i);
	        }
	    }
	    
	    while(st.empty()!=true)
	    {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    
	    return topo;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
class Solution {
public:
    bool hasCycle(vector<int> adj[], vector<int>& vis ,vector<int>& dfsVis, int curr){
        vis[curr] = true;
        dfsVis[curr] = true;
        for(auto elem:adj[curr]){
            if( vis[elem] && dfsVis[elem] )
                return true;
            else if(!vis[elem]){
                if(hasCycle(adj, vis, dfsVis, elem))
                    return true;
            }
        }
        dfsVis[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto elem:prerequisites){
            adj[elem[1]].push_back(elem[0]);
        }
        vector<int> vis(numCourses);
        vector<int> dfsVis(numCourses);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i])
                if (hasCycle(adj, vis, dfsVis, i)){
                    return false;
                }
        }
  
        return true;

    }
};
class Solution {
public:
    long long fuel;
    int dfs(vector<int> adj[], int curr, int seats, vector<int> & vis){

        int rep = 1;
        // start dfs
        vis[curr]=1;
        for(auto elem:adj[curr]){
            if(vis[elem]==0){
                rep +=  dfs(adj, elem, seats, vis);
            }
        }
        if(curr != 0)
        {
           /*if(seats > rep) fuel += 1;
            else
                fuel += (rep/seats) + (rep%seats);*/
            fuel += ceil((double)rep/seats);
            //fuel += (rep + seats - 1)/(long long)seats;
        }
        //vis[curr]=0;
        return rep;

    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // make adjacency
        vector<int> adj[roads.size()+1];

        for(auto elem:roads){
            adj[elem[0]].push_back(elem[1]);
            adj[elem[1]].push_back(elem[0]);
        }
        vector<int> vis(roads.size()+1, 0);
        dfs(adj, 0, seats, vis);
        return fuel;
    }
};
// Orignal solution thought is TLE which does dfs for all queries
// leading O(n^2) complexity.
// Sorting the queries and edge list help us include edges
// progressively and check if the queried node are in the same component.
class UnionFind {
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    void join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);

        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
    }

    bool areConnected(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        return group1 == group2;
    }
};
class Solution {
public:
    bool dfs(int curr, int des, vector<int> adj[], vector<bool> &vis) {
        if(curr == des) {
            return true;
        }
        vis[curr] = true;
        for(auto elem:adj[curr]) {
            if(!vis[elem]) {
                if(dfs(elem, des, adj, vis))
                    return true;
            }
        }
        vis[curr] = false;
        return false;
    }
    static bool comp(vector<int> &A, vector<int> &B) {
        return A[2]<B[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        UnionFind uf(n);
        sort(edgeList.begin(), edgeList.end(), comp);
        unordered_map<int, unordered_set<int>> mp;
        // cache indexes before sorting queries 
        // to be able populate ans correctly
        for(int i = 0;i<queries.size();i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), comp);
        vector<int> adj[n];
        int qi=0;
        int ei=0;
        while(qi<queries.size()) {
           
            while(ei<edgeList.size() && edgeList[ei][2]<queries[qi][2]){
                //adj[edgeList[ei][0]].push_back(edgeList[ei][1]);
                //adj[edgeList[ei][1]].push_back(edgeList[ei][0]);
                int node1 = edgeList[ei][0];
                int node2 = edgeList[ei][1];
                uf.join(node1, node2);
                ei++;
            }
            
            vector<bool> vis(n);
            //ans[queries[qi][3]] = dfs(queries[qi][0], queries[qi][1], adj, vis);
            ans[queries[qi][3]] = uf.areConnected(queries[qi][0], queries[qi][1]);
            qi++;
        }
        return ans;
    }
};
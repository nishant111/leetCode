class Solution {
public:
    vector<vector<int>> dp;
    int checksForCycleAndColor(int node, vector<int> adj[], unordered_set<int> &vis, string &colors, unordered_set<int> &path) {
        if(path.find(node)!=path.end()) {
            return INT_MAX;
        }
        if(vis.find(node)!=vis.end()) {
            return 0;
        }

        vis.insert(node);
        path.insert(node);
        dp[node][colors[node] - 'a'] = 1;
        int max_elem = INT_MIN;
        for(auto nei: adj[node]) {
            if (checksForCycleAndColor(nei, adj, vis, colors, path) == INT_MAX)
                return INT_MAX;

            for(int i = 0;i<26;i++) {
                int adj = i == colors[node]-'a'? 1 : 0;
                dp[node][i] = max(dp[nei][i] + adj,
                                    dp[node][i] );
                max_elem = max(max_elem, dp[node][i]);
            }
        }

        path.erase(node);
        return max_elem;

    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        if(edges.size()==0)
            return 1;
        vector<int> adj[n];
        for(auto elem:edges) {
            adj[elem[0]].push_back(elem[1]);
        }
        unordered_set<int> vis;
        unordered_set<int> path;
        int res = INT_MIN;
        dp.resize((n), vector<int>(26,0));
        for(int i = 0;i<n;i++) {
            if(vis.find(i) == vis.end() ) {
                res = max(checksForCycleAndColor(i, adj, vis,colors, path), res);
                if(res == INT_MAX)
                    return -1;
                    
            }
        }
        return res;
    }
};
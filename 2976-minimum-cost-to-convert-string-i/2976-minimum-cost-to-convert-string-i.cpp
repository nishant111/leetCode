class Solution {
public:
    
    void bfs( char c, vector<pair<int,int>> adj[], vector<long long>& vis ){
        priority_queue<pair<char, int>> pq;
        pq.push({c,0});
        
        vis[c-'a'] = 0;
        while(!pq.empty()){
            int size = pq.size();
            while(size-->0){
                pair<int, int> curr = pq.top();
                pq.pop();
                for(auto n:adj[curr.first-'a']){
                    long long dton = curr.second+n.second;
                    if(vis[n.first-'a'] == -1 || vis[n.first-'a']>curr.second+n.second){
                        vis[n.first-'a'] = dton;
                        pq.push({n.first, dton});
                    }
                }
            }
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {    
        vector<pair<int,int>> adj[26];
        for(int i = 0;i<original.size();i++){
            adj[original[i] - 'a'].push_back({changed[i], cost[i]});
        }
        vector<int> minCosts(26, -1);
        unordered_map<char, vector<long long>> mp;
        for(char i = 'a' ;i<='z';i++){
            vector<long long> vis(26, -1);
            bfs( i, adj, vis );
            mp[i] = vis;
        }
        
        
        long long ans = 0;
        for(int i = 0;i<source.size();i++){
            if(source[i] != target[i]){
                if(mp[source[i]][target[i] -'a'] == -1)
                    return -1;
                ans += mp[source[i]][target[i] -'a'];
            }
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(string start,  unordered_map<string, vector<string>>& adj, vector<string> &ret,  unordered_set<string>& vis){
        
        vis.insert(start);
        ret.push_back(start);
        for(auto nei:adj[start]){
            if(vis.find(nei)==vis.end()){
                dfs(nei, adj, ret, vis);
            }
        }
        return;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> adj;
        for(auto el:accounts){
            string name = el[0];
            string firstEmail = el[1];
            int i = 2;
            while(i<el.size()){
                adj[firstEmail].push_back(el[i]);
                adj[el[i]].push_back(firstEmail);
                i++;
            }
        }
        
        unordered_set<string> vis;
        vector<vector<string>> ans;
        for(auto el:accounts){
            vector<string> ret;
            if(vis.find(el[1]) == vis.end())
            {
                // not visited
                ret.push_back(el[0]);
                dfs(el[1], adj, ret, vis);
                sort(ret.begin()+1, ret.end());
                ans.push_back(ret);
                
            }
            
        }
        return ans;
        
    }
};
class Solution {
public:
    string dfs(string src,
               unordered_map<string,vector<string>>& adj){
        for(auto ngb:adj[src]){
            string ret = dfs(ngb, adj);
            if(ret.length()!=0){
                return ret;
            }
        }
        return src;
    }
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>> adj;
        string src = "";
        src=paths[0][0];
        for(auto el:paths){
            adj[el[0]].push_back(el[1]);
        }
        
        return dfs(src, adj);
    }
};
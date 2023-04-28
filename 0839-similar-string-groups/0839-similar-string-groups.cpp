class Solution {
public:
    void dfs(int curr, vector<int> adj[], vector<bool>& vis) {
        if(vis[curr]==true)return;
        vis[curr]=true;
        for(auto elem:adj[curr]){
            if(!vis[elem]){
                dfs(elem, adj, vis);
            }
        }
    }
    int isSimilar(string toCompare, string compareAgainst) {
        int mismatch = 0;
        int l = 0;
        int r = 0;
        while(l<toCompare.size()){
            if(toCompare[l++]!=compareAgainst[r++])
            mismatch++;
            if(mismatch>2)
                break;
        }
        return mismatch == 0 || mismatch == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
       // make connected graph of similar strings
        vector<int> adj[strs.size()];
       for(int i = 0;i<strs.size();i++){
           for(int j = i+1;j<strs.size();j++) {
                if(isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
           }
       }
       vector<bool> vis(strs.size(), false);
       int count = 0;
       for(int i=0;i<strs.size();i++){
           if(!vis[i]){
               count++;
               dfs(i, adj, vis);
           }
       }
       return count;
    }
};
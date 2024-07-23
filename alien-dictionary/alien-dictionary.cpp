class Solution {
public:
    bool dfs(int curr, vector<int> adj[], stack<int>& st, vector<int>& vis, vector<int>& pathVis ){
        vis[curr] = true;
        pathVis[curr] = true;
        for(auto nei:adj[curr]){
            if(!vis[nei]){
                if(dfs(nei, adj, st, vis, pathVis))
                    return true;
            }
            else if(pathVis[nei] == true)
                return true;
        }
        pathVis[curr] = false;
        st.push(curr);
        return false;;
    }
    
    bool find(vector<int> a, int targ){
        for(auto el:a){
            if(el==targ)
                return true;
        }
        return false;
    }
    
    string alienOrder(vector<string>& words) {
        vector<int> adj[26];
        unordered_set<char> s;
        for(auto el:words){
            for(auto e:el)
                s.insert(e);
        }
        for(int i = 0;i<words.size()-1;i++){
            string first = words[i];
            string second = words[i+1];
            //cout<<first<<" "<<second<<"\n";
            bool misMatch=false;
            for(int j = 0;j<min(first.size(), second.size());j++){
                if(!misMatch && first[j]!=second[j]){
                    adj[first[j]-'a'].push_back(second[j]-'a');
                    misMatch=true;
                    break;
                }
            }
            
            if(misMatch == false && first.size()>second.size()){
                // ettb is before ett
                return "";
            }
        }
        
        // do a topo sort
        stack<int> st;
        string topo = "";
        vector<int> vis(26, 0);
        vector<int> pathVis(26, 0);
        for(auto el:s){
            if(!vis[el-'a']){
                if(dfs(el-'a', adj, st, vis, pathVis))
                    return "";
            }
        }
        while(!st.empty()){
            s.erase(st.top()+'a');
            topo = topo + char(st.top() + 'a');
            st.pop();
        }
        for(auto el:s){
            topo = topo + el;
        }
        return topo;
        
    }
};
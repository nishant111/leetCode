class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> st;
        for (auto el:edges){
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
            st.insert(el[0]);
            st.insert(el[1]);
        }
        for(auto el:adj){
            if(el.second.size()==st.size()-1)
                return el.first;
        }
        return -1;
    }
};
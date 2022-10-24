class Solution {
public:
    
    int dfs(vector<string> &arr, int curr, unordered_set<char> st = {})
    {
        if(curr==arr.size())
            return st.size();
        bool canPick = true;
        int nonPick = dfs(arr, curr+1, st) ;
        int pick = INT_MIN;
        for(auto elem:arr[curr])
        {
        if(st.find(elem) != st.end())
            canPick = false;
        st.insert(elem);
        }
        if(canPick)
            pick = dfs(arr, curr+1, st);
        return max(nonPick,pick);
        
    }
    
    int maxLength(vector<string>& arr) {
        return dfs(arr, 0);
        
    }
};
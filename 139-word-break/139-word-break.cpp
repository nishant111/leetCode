class Solution {
public:    
    int dfs(string s, unordered_set<string> &st, int curr, vector<int> &dp)
    {
        if(curr >= s.size()) return true;
        if(dp[curr]!=-1) return dp[curr];
       
        for(int i = curr;s[i]!='\0';i++)
        {
            string fp = s.substr(curr, i-curr+1);
            if(st.find(fp)!=st.end())
            {
                //recurse ahead and check further possibilities
                if(dfs(s, st, i+1, dp ))
                    return dp[curr] = true;
            }
        }
        return dp[curr] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> part;
        unordered_set <string> st;
        vector<int> dp(s.size(), -1);
        for(auto i:wordDict) st.insert(i);
        return dfs(s, st, 0,dp);
    }
};
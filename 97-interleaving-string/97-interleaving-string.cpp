class Solution {
public:
    
    int dfs(string s1, int i1, string s2, int i2, string s3, string res, vector<vector<int>> &dp)
    {
        if(i1 == s1.size() && i2 == s2.size() && res == s3)
            return 1;
        int ans = 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if( (i1<s1.size() && s1[i1] == s3[i1+i2] && dfs(s1, i1+1, s2, i2, s3, res+s1[i1], dp) ) ||
            (i2<s2.size() && s2[i2] == s3[i1+i2] && dfs(s1, i1, s2, i2+1, s3, res+ s2[i2], dp)))
        {
            ans = 1;
        }
        return dp[i1][i2] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!= s1.size() + s2.size())
            return false;
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, -1));
        return dfs(s1, 0, s2, 0, s3, "", dp);
        
    }
};
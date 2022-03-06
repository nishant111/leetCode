class Solution {
public:
     int lcs(string &s1, string &s2, int s1i, int s2i, vector<vector<int>>& dp)
    {
        if(s1i<0 || s2i < 0) return 0;
        if(dp[s1i][s2i]!=-1) return dp[s1i][s2i];
        int ans = 0;
        if(s1[s1i] == s2[s2i])
        {
           ans = 1+lcs(s1,s2, s1i-1, s2i-1, dp);
        }
        else
        {
            ans =   max(lcs(s1, s2, s1i-1, s2i, dp) , lcs(s1, s2, s1i, s2i-1, dp));
        }
        return dp[s1i][s2i] = ans;
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        string rs ="";
        for(int i = s.length()-1;i>=0;i--)
        {
            rs.push_back(s[i]);
        }
        
        int res =  lcs(s, rs, s.size()-1, rs.size()-1, dp);
        return s.size()-res;
    }
};
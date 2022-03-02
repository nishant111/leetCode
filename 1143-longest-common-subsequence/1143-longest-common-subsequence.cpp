class Solution {
public:
    int dfs(string &text1, string &text2, int i1, int i2, vector<vector<int>> &dp)
    {
        if(i1>= text1.size() || i2>= text2.size()) return 0;
        if(dp[i1][i2]!= -1) return dp[i1][i2];
        if(text1[i1] == text2[i2])
        {
            return dp[i1][i2] = 1+dfs(text1, text2, i1+1, i2+1, dp);
        }
        else
        {
            return dp[i1][i2] = max(dfs(text1, text2, i1+1, i2, dp),dfs(text1, text2, i1, i2+1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        int ans =  dfs(text1, text2, 0, 0, dp);
        return ans;
    }
};
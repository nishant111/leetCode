class Solution {
public:
    int dp[501][501];
    int dfs(string word1, string word2, int i1, int i2)
    {
        if(i1<0 || i2 < 0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(word1[i1] == word2[i2])
        {
            return dp[i1][i2] = (1+dfs(word1, word2, i1-1, i2-1));
        }
        else
        {
            return dp[i1][i2] = max(dfs(word1, word2, i1-1, i2),
                      dfs(word1, word2, i1, i2-1));
        }
    }
    int minDistance(string word1, string word2) {
        // find longest common subsequence
        memset(dp, -1, sizeof(dp));
        int lcs = dfs(word1, word2, word1.size()-1, word2.size()-1);
        
        int ans = word1.size()-lcs + (word2.size()-lcs);
        return ans;
        
    }
};
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
    int longestPalindromeSubseq(string s) {
        //use lcs.
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        string rs ="";
        for(int i = s.length()-1;i>=0;i--)
        {
            rs.push_back(s[i]);
        }
        
        return lcs(s, rs, s.size()-1, rs.size()-1, dp);
    }
};



/*class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    int dfs(string &s, int curr, string currS) {
        if(curr == s.size())
        {
            if(isPalindrome (currS))
            return currS.size();
            return 0;
        }

        int pick = 0;
        int np = 0;

        np = dfs(s, curr+1, currS);

        currS += s[curr];
            pick = dfs(s, curr+1, currS);
        
        return max(pick, np);
    }
    int longestPalindromeSubseq(string s) {
        string currS= "";
        return dfs(s, 0, currS);
    }
};*/
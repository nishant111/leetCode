class Solution {
public:
    
    bool dfs(string s, string p, int si, int pi, vector<vector<int> >& dp){
        if(si == s.size() && pi == p.size())
            return true;
        
        if(pi>=p.size())
            return false;
        if(dp[si][pi] != -1)
            return dp[si][pi];
        
        bool charsMatch = si<s.size() && ( s[si] == p[pi] || p[pi] == '.' );
        bool nextOneStar = (pi+1<p.size() && p[pi+1] == '*');
        bool isMatch;
        if(charsMatch){
            if(nextOneStar){
                isMatch = dfs(s, p, si, pi+2, dp) || dfs(s, p, si+1, pi, dp);
            }
            else{
                isMatch = dfs(s, p, si+1, pi+1, dp);
            }
        }
        else{
            if(nextOneStar){
                // zero count .*, a*
                isMatch = dfs(s, p, si, pi+2, dp);
            }
            else{
                isMatch = false;
            }
        }
        return dp[si][pi] = isMatch;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int> > dp(s.size()+1, vector<int> (p.size() + 1, -1));
        return dfs(s, p, 0, 0, dp);
    }
};
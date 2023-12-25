class Solution {
public:
    int dfs(string &s, int curr, vector<int>& dp){
        if(curr>=s.size()){
            return 1;
        }
        if(s[curr]=='0')
            return 0;
        if(dp[curr]!=-1) return dp[curr];
        int ways = 0;
        
        ways += dfs(s, curr+1, dp);
        int t = 0;
        if(curr+1<s.size())
            t = stoi(s.substr(curr, 2));
            if(t>26)
                t=0;
        if(t!=0){
            ways += dfs(s, curr+2, dp);
        }
        return dp[curr]=ways;
    }
    
    int numDecodings(string s) {
        unordered_map<int , char> mp;
        vector<int> dp(s.size()+1, -1);
        return dfs(s, 0, dp);
        
    }
};
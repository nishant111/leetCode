class Solution {
public:
    // edge case:
    // leading zeros 
    // number greater than 26
    int dfs(string &s, int curr, vector<int>& dp){
        
        if(s[curr]=='0')
            return 0;
        if(curr==s.size())
            return 1;
        if(dp[curr]!= -1){
            return dp[curr];
        }
        int number = 0;
        int ways = 0;
        ways += dfs(s, curr+1, dp);
        if(curr+1<s.size()){
            number = (s[curr]-'0')*10 + (s[curr+1]-'0');
            if(number>=1 && number <=26){
                ways += dfs(s, curr+2, dp);
            }
            else{
                return ways;
            }
        }
        return dp[curr]=ways;
    }
    
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return dfs(s, 0, dp);
    }
};
class Solution {
public:
    long long MOD = 1000000007;
    int dfs(string &s, int &k, int curr, vector<int>& dp) {
        if(s[curr] == '0') return 0LL;
        if(curr == s.size())
            return 1LL;
        long long currNumber = 0;
        long long ans = 0;
        if(dp[curr]!=-1)return dp[curr];
        for(int i = curr;i<s.size();i++) {
            currNumber = (currNumber*10) + (s[i]-'0');
            if(currNumber < 1 || currNumber >k){
                break;
            }
            ans = ans + (long long) dfs(s, k, i+1, dp);
        }
        return dp[curr]= (long long)ans%MOD;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size()+1, -1);
        return dfs(s, k, 0, dp)%MOD;
    }
};
class Solution {
public:
    int dfs(string& s, int curr, unordered_set<string> &d, vector<int>& dp ){
        if(curr == s.size()){
            return 0;
        }
        if (dp[curr] != -1 ) return dp[curr];
        // always tries skipping, if skipping gives better answer why not skip
        // even if word exist in dictionary
        int ans = 1+ dfs(s, curr+1, d, dp);
        for(int j = curr;j<s.size();j++){
            //t += s[j];
            if(d.find(s.substr(curr, j-curr+1)) != d.end())
            {
                //found this partitioned word in the dictionary
                ans = min(ans, dfs(s, j+1, d, dp));
            }
        }
        return dp[curr] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> d;
        vector<int> dp(s.size(), -1);
        for(auto elem:dictionary){
            d.insert(elem);
        }
        
        return dfs(s, 0, d, dp);
    }
};
class Solution {
public:
    int mod=1000000007;
    int dfs(int low, int high, int zero, int one, int length, vector<int>& dp){
        if(length > high)
            return 0;
        if(dp[length]!=-1) return dp[length];
        long long ans = 0;
        if(length>=low && length<=high) ans++;
        //append zero
        ans += dfs(low, high, zero, one, length+zero, dp)%mod;
        //append one
        ans += dfs(low, high, zero, one, length+one, dp)%mod;
        return dp[length]=ans%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return dfs(low, high, zero, one, 0, dp);
    }
};
/*
class Solution {
public:
    int dfs(int low, int high, vector<string>& in, int curr, string currStr){
        if(currStr.size()>high)
            return 0;
        int ans = 0;
        if(currStr.size()>=low && currStr.size()<=high) ans++;
        //pick and stay here
        ans = ans + dfs(low, high, in, curr, currStr+in[curr]);
        //nonpick with wrap around
        ans += dfs(low, high, in, (curr+1)%in.size(), currStr+in[(curr+1)%in.size()]);
        return ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<string>
        vector<string> in(2);
        string zeros = "";
        for(int i = 1;i<=zero;i++){
            zeros+='0';
        }
        string ones = "";
        for(int i = 1;i<=one;i++){
            ones+='0';
        }
        in[0]=zeros;
        in[1]=ones;
        return dfs(low, high, in, 0, "");
    }
};/*/
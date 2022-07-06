class Solution {
public:
    int fibinner(int n, vector<int> &dp) {
        if(n == 0) return dp[n] = 0;
        if(n==1) return dp[n] = 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (fibinner(n-2, dp) + fibinner(n-1, dp));
    }
    int fib(int n){
        vector<int> dp(n+1, -1);
        return fibinner(n, dp);
    }
};
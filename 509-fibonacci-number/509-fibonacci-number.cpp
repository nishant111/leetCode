class Solution {
public:
    int dp[31];
    int fibinner(int n) {
        if(n == 0) return dp[n] = 0;
        if(n==1) return dp[n] = 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (fib(n-2) + fib(n-1));
    }
    int fib(int n){
        memset(dp, -1, sizeof(dp));
        return fibinner(n);
    }
};
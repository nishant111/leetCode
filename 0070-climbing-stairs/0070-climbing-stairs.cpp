class Solution {
public:
    int dp[46]={0};
    int climbStairs(int n) {
        if (n==0)
            return dp[n] = 1;
        if(n<0)
            return 0;
        cout <<"dp["<<n<<"]"<<dp[n]<<"\n";
        if(dp[n]!=0) return dp[n];
        int ways = 0;
        ways += climbStairs(n-1) + climbStairs(n-2);
        return dp[n]=ways;
    }
};
class Solution {
public:
    int MOD = 1000000007;
    int maxi;
    int size;
    int dfs(int i, int maxSoFar, int remain, vector<vector < vector<int> > >& dp){
        
        if(i==size && remain == 0)
            return 1;
        else if(i==size && remain != 0)
            return 0;
        if(remain<0)
            return 0;
        if(dp[i][maxSoFar][remain]!=-1)
            return dp[i][maxSoFar][remain];
        int ways = 0;
        // try placing value less than maxSoFar
        // as a consequence remain remains unchanged
        for(int val = 1; val<=maxSoFar; val++ ){
            ways = ( ways + dfs(i+1, maxSoFar, remain, dp) ) % MOD;
        }
        // try placing value more than maxSoFar
        // as a consequence remain becomes remain-1
        for(int val = maxSoFar+1; val<=maxi; val++ ){
            ways = ( ways + dfs(i+1, val, remain-1, dp ) ) % MOD;
        }
        return dp[i][maxSoFar][remain]=ways;
    }
    
    int numOfArrays(int n, int m, int k) {
        maxi = m;
        size = n;
        vector<vector<vector<int>>> dp;
         dp = vector(n, vector(m + 1, vector(k + 1, -1)));
        //vector<vector < vector<int> > > dp(n,(vector<vector<int>>(m+1, (vector<int>(k+1, -1)))));
        return dfs(0, 0, k, dp);
    }
};
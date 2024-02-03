class Solution {
public:
    int dfs(vector<int>& arr, int k , int curr, vector<int>& dp){
        if(curr>=arr.size())
            return 0;
        if(dp[curr]!=-1) return dp[curr];
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = curr;i<curr+k && i<arr.size();i++){
            maxi = max(maxi, arr[i]);
            sum = max(sum, (maxi * (i-curr+1)) + dfs(arr, k, i+1, dp));
        }
        return dp[curr] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return dfs(arr, k, 0, dp);
    }
};
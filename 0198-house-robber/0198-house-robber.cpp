class Solution {
public:
    //int dp[101] = {-1};
    int dfs(vector<int>& nums, int curr,  vector<int>& dp){
        if(curr >= nums.size())
            return 0;
        if(dp[curr]!=-1) return dp[curr];
        int sum = 0;
        // rob
        sum = max(nums[curr] + dfs(nums, curr+2, dp), dfs(nums, curr+1, dp));
        return dp[curr]=sum;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return dfs(nums, 0, dp);
    }
};
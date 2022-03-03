class Solution {
public:
    bool dfs(vector<int> &nums, int curr, int sum1, vector<vector<int>> &dp)
    {
        
        if(sum1 == 0) return true;
        if(curr<0 ) return false;
        if(dp[curr][sum1]!=-1) return dp[curr][sum1];
        int pick = false;
        if(sum1-nums[curr]>=0)
            pick = dfs(nums, curr-1, sum1-nums[curr], dp);
        int nonpick = dfs(nums, curr-1,sum1, dp);
        bool rval;
        if(pick || nonpick) rval = true;
        else rval = false;
        return dp[curr][sum1]=rval;
    }
    bool canPartition(vector<int>& nums) {
        int sum1 = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum1 += nums[i];
        }
        if((sum1)%2!=0) return false;
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum1 + 1, -1));
        
        return dfs(nums, nums.size()-1, sum1/2, dp); 
    }
};
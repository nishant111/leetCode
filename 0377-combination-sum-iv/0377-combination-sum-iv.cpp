class Solution {
public:
    int dfs(vector<int> &nums, int curr, int target, int currSum, vector<vector<int>> & dp){
        if(curr == nums.size())
            return 0;
        if(currSum > target)
            return 0;
        if(currSum == target)
            return 1;
        if(dp[curr][currSum]!=-1) return dp[curr][currSum];
        //pick and restart from begining
        int pickways = dfs(nums, 0, target, currSum+nums[curr], dp);
        
        //skip and restart from begining
        int nonpickways = dfs(nums, curr+1, target, currSum, dp);
        return dp[curr][currSum] = pickways + nonpickways;
    }
    
    int combinationSum4(vector<int>& nums, int target){
        vector<vector<int>> dp(nums.size(), vector<int>(2000, -1) );
        return dfs(nums, 0, target, 0, dp);
    }
};
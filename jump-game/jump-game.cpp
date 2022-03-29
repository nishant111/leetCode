class Solution {
public:
    bool dfs(vector<int> & nums, int curr, vector<int> &dp)
    {
        if(curr >= nums.size()) return dp[curr]= false;
        if(curr == nums.size()-1) return dp[curr] = true;
        if(dp[curr]!=-1) return dp[curr];
        bool res;
        for(int i = nums[curr];i>0;i--)
        {
            if(curr+i < nums.size())
            {
                if(dfs(nums, curr+i, dp))
                    return dp[curr] = true;
            }
        }
        return dp[curr] = false;
    }
    bool canJump(vector<int>& nums) {
       vector<int> dp(nums.size()+1, -1);
       return dfs(nums, 0, dp);
    }
};
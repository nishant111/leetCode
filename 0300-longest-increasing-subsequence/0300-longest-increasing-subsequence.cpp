class Solution {
public:
    int dfs(vector<int> &nums, int curr, vector<int>& lis){
        if(curr>=nums.size()){
            return 0;
        }
        if(lis[curr]!=-1) return lis[curr];
        int ans = 0;
        for(int i = curr+1;i<nums.size();i++){
            if(nums[i]>nums[curr]){
                ans = max(ans, 1+dfs(nums, i, lis));
            }
        }
        return lis[curr]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans = INT_MIN;
        vector<int> lis(nums.size()+1, -1);
        for(int i = 0;i<nums.size();i++){
            int t = 1 + dfs(nums, i, lis);
            ans = max(t, ans);
        }
        return ans;
    }
};
class Solution {
public:
    int ans=0;
    void dfs(vector<int>& nums, int curr, int currXor){
        if(curr>=nums.size()){
            ans += currXor;
            return;
        }
        dfs(nums, curr+1, currXor ^ nums[curr]);
        dfs(nums, curr+1, currXor);
        return;
        
    }
    int subsetXORSum(vector<int>& nums) {
         dfs(nums, 0, 0);
         return ans;
    }
};
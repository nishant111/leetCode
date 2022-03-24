class Solution {
public:
    void swap(vector<int> &nums, int left, int right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    void dfs(vector<int> nums, vector<vector<int>> &ans, int curr)
    {
        if(curr >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = curr;i<nums.size();i++)
        {
            swap(nums, i, curr);
            dfs(nums,  ans, curr+1);
            swap(nums, i, curr);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        dfs(nums, ans, 0);
        return ans;
    }
};
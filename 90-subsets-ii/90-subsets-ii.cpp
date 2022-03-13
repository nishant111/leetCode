class Solution {
public:
    void dfs(vector<int> & nums, vector<int> &tmp, vector<vector<int>> &ans, int curr)
    {
        if(curr >= nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        tmp.push_back(nums[curr]);
        dfs(nums, tmp, ans, curr+1);
        
        tmp.pop_back();
        while(curr+1 < nums.size() && nums[curr+1] == nums[curr])
        {
            curr++;
        }
        dfs(nums, tmp, ans, curr+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, tmp, ans, 0);
        return ans;
    }
};
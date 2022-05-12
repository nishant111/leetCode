class Solution {
public:
    
    void dfs(vector<int> nums, vector<vector<int>> &ans, int curr,
            set <vector<int>> &s)
    {
        if(curr >= nums.size())
        {
            if(s.find(nums) == s.end())
            {
                ans.push_back(nums);
                s.insert(nums);
            }
        }
        for(int i = curr;i<nums.size();i++)
        {
            if(i!=curr && nums[i] == nums[curr])
            {
                continue;
            }
            else
            {
                swap(nums[i], nums[curr]);
                dfs(nums, ans, curr+1,s);
                swap(nums[i], nums[curr]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        dfs(nums, ans, 0, s);
        return ans;
    }
};
class Solution {
public:
    void dfs (vector<int> & nums, int curr ,vector <vector<int>> & res,vector<int> & temp  )
    {
        if(curr == nums.size())
        {
            /* reached end */
            res.push_back(temp);
            return;
        }
        /* assume pick */
        temp.push_back(nums[curr]);
        dfs(nums, curr+1, res, temp );
        
        /* asume non pick */
        temp.pop_back();
        dfs(nums, curr+1, res, temp );
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> res;
        vector<int> temp;
        dfs(nums, 0, res, temp );
        return res;
    }
};
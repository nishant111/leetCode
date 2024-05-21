class Solution {
public:
    void dfs(vector<int>& nums, int curr, vector<vector<int>> &ans, vector<int> &currSet){
        if(curr>=nums.size()){
            ans.push_back(currSet);
            return;
        }
        
        //take
        currSet.push_back(nums[curr]);
        dfs(nums, curr+1, ans, currSet);
        //dont take
        currSet.pop_back();
        dfs(nums, curr+1, ans, currSet);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSet;
        dfs(nums, 0 , ans, currSet);
        return ans;
    }
};
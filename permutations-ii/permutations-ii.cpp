class Solution {
public:
    int n;
    
    void dfs(vector<int>& nums, int curr, set<vector<int>> &ans){
        if(curr==n){
            ans.insert(nums);
            return;
        }
        
        for(int i = curr;i<n;i++){
            if(i!=curr && nums[i] == nums[curr]){
                continue;
            }
            swap(nums[curr], nums[i]);
            dfs(nums, curr+1, ans);
            swap(nums[curr], nums[i]);
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        set<vector<int>> ans;
        dfs(nums, 0, ans);
        vector<vector<int>> a;
        for(auto el:ans){
            a.push_back(el);
        }
        return a;
    }
};
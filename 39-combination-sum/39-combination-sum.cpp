class Solution {
public:
    void dfs(vector<int> &cand, vector<int> &tmp,
            vector<vector<int>> &ans, int targ, int curr)
    {
        if(curr >= cand.size() && targ != 0) return;
        if(targ <0 ){
            return;
        }
        else if(targ == 0){
            ans.push_back(tmp);
            return;
        }
        
        //pick
        tmp.push_back(cand[curr]);
        dfs(cand, tmp, ans, targ-cand[curr], curr);
        
        //non-pick
        tmp.pop_back();
        dfs(cand, tmp, ans, targ, curr+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ans;
        dfs(candidates, tmp, ans ,target, 0);
        return ans;
    }
};
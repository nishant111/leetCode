class Solution {
public:
    void dfs(vector<int> &cand, vector<int> &tmp, vector<vector<int>> &ans,
            int targ, int curr)
    {
        if(targ == 0)
        {
            ans.push_back(tmp);
            return;
        }
        if(targ < 0 || curr>=cand.size())
        {
            //not possible to recreate targ
            return;
        }
        
        
        //pick
        tmp.push_back(cand[curr]);
        dfs(cand, tmp, ans, targ-cand[curr], curr+1);
        
        //non-pick
        tmp.pop_back();
        while(curr+1<cand.size() && cand[curr] == cand[curr+1])
        {
            // goes to the last occurrance of the dup elem in sorted list
            curr++;
        }
        dfs(cand, tmp, ans, targ, curr+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, tmp, ans, target, 0);
        return ans;
    }
};
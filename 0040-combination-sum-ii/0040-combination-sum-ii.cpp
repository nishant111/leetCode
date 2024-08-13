class Solution {
public:
    void dfs( vector<int>& candidates, int pos, int target, vector<int>& picked, vector<vector<int>>& ans, int currSum ){
        if(currSum == target){
            ans.push_back(picked);
            return;
        }
        
        if( currSum>target )
            return;
        if(currSum < target && pos==candidates.size())
            return;
        
        // try picking
        picked.push_back( candidates[pos] );
        dfs( candidates, pos+1, target, picked, ans, currSum+candidates[pos]);
        picked.pop_back();
        
        // try skipping
        while( pos+1<candidates.size() && candidates[pos] == candidates[pos+1]) pos++;
        dfs( candidates, pos+1, target, picked, ans, currSum );
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> picked;
        dfs( candidates, 0, target, picked, ans, 0 );
        return  ans;
    }
};
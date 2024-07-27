class Solution {
public:
    void dfs(unordered_map<int, int>& s, vector<int> currP,vector<vector<int>>& ans )
    {
        if(currP.size()==n){
            ans.push_back(currP);
            return;
        }
        
        for(auto el:s){
            if(el.second>0){
                currP.push_back(el.first);
                s[el.first]--;
                dfs(s, currP, ans);
                currP.pop_back();
                s[el.first]++;
            }
        }
        return;
    }
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> s;
        for(auto el:nums){
            s[el]++;
        }
        n = nums.size();
        vector<int> currP;
        vector<vector<int>> ans;
        dfs(s, currP, ans);
        return ans;
    }
};
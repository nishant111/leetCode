class Solution {
public:
    void dfs(int count, int sum, int curr, vector<vector<int>> &ans, vector<int> tmp)
    {
        if(count == 0 && sum  == 0)
        {
            ans.push_back(tmp);
            return;
        }
        else if(sum<0 || (sum>0 && count==0) )
        {
            //base case return
            return;
        }
        
        for(int i = curr;i<=9;i++)
        {
            if( (count - 1 >= 0) && (sum-i >= 0) )
            {
                tmp.push_back(i);
                dfs(count-1, sum-i, i+1, ans, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(k, n, 1, ans, tmp);
        return ans;
    }
};
class Solution {
public:
/*
Without DP O(n^2)
with DP O(n)


*/
    int dfs(int curr, vector<int> &nums, vector<int> &lis)
    {
        if(curr==0) return 1;
        if(lis[curr]!= -1) return lis[curr];
        int ans =1;
        for(int i = curr-1;i>=0;i--)
        {
            if(nums[i]< nums[curr])
            {
                ans = max(dfs(i, nums, lis)+1, ans);
            }
        }
        return lis[curr] = ans;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), -1);
        int ans=0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            int tmp = dfs(i, nums, lis);
            ans = max(tmp, ans);
        }
        return ans;
        /*
        if(nums.size()==0) return 0;
        int rval = 1;
        for(int j = 1;j<nums.size();j++)
        {
            for(int i = 0;i<j;i++)
            {
                if(nums[i]<nums[j])
                {
                    lis[j] = max(lis[i]+1, lis[j]);
                    cout<<"lis "<< j <<" is "<< lis[j]<<"\n";
                }
                if(rval<lis[j])
                    rval = lis[j];
            }
        }
        return rval;
        */
    }
};
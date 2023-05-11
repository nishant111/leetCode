class Solution {
public:
    int dfs(vector<int>& nums1, vector<int>& nums2, int i1, int i2, unordered_map<int, vector<int>>& m1, unordered_map<int, vector<int>>& m2, vector<vector<int>> &dp){
        if(i1<0||i1>=nums1.size()||i2<0||i2>=nums2.size())
            return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        auto pair = m1[nums2[i2]];
        int ans =0;
        for(auto elem:pair){
            if(elem>=i1){
                //make pair
                ans =max(ans , 1+dfs(nums1, nums2, elem+1, i2+1, m1, m2, dp));
            }
        }
        //try skipping pair and see if max is acheived
        ans = max(ans, dfs(nums1, nums2, i1, i2+1, m1, m2, dp));
        return dp[i1][i2]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> m1, m2;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, -1));
        for(int i = 0;i<nums1.size();i++){
            m1[nums1[i]].push_back(i);
        }
        for(int i = 0;i<nums2.size();i++){
            m2[nums2[i]].push_back(i);
        }
        return dfs(nums1, nums2, 0, 0, m1, m2, dp);
    }
};
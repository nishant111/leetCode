class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<pair<int, int>> dp(nums.size());

        dp[0] = {nums[0], nums[0]};
        int tmp;
        int ans = INT_MIN;
        ans = max(dp[0].second, ans);
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == 0){
                ans = max(ans, 0);
                dp[i] = {1, 1};
                continue;
            }
            tmp = max(dp[i-1].first * nums[i], dp[i-1].second * nums[i] );
            dp[i].second = max(nums[i], tmp);

            tmp = min(dp[i-1].first * nums[i] , dp[i-1].second*nums[i]);
            dp[i].first = min(nums[i], tmp);
            ans = max(dp[i].second, ans);
        }
        return ans;
    }
};
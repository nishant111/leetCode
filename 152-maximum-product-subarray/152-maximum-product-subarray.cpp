#include<bits/stdc++.h>
using namespace std;
#define max(a, b) a>b?a:b;
#define min(a,b) a<b?a:b;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <pair<int, int>> dp(nums.size()); // min, max
        dp[0] = {nums[0], nums[0]};
        int max = nums[0];
        int i = 1;
        for(;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                dp[i]={1,1};
                max= max(0, max);
                continue; //dont kill the sum
            }
            int tmp = max( (dp[i-1].first) * nums[i], (dp[i-1].second)*nums[i]);
            dp[i].second = max(tmp, nums[i]);
            tmp = min(dp[i-1].first * nums[i], dp[i-1].second*nums[i]);
            dp[i].first = min(tmp, nums[i])
            
            tmp= max(dp[i].first, dp[i].second);
            max = max(tmp, max);
        }
        return max;
    }
};
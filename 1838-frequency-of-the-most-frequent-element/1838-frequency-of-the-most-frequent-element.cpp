class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        long long curr = 0;
        int ans = 0;
        for(;r<nums.size();r++)
        {
            curr +=nums[r];
            int targ = nums[r];
            
            while(l<nums.size() && (long long)(r-l+1)*(long long)targ-curr>(long long)k){
                curr -= nums[l++];
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
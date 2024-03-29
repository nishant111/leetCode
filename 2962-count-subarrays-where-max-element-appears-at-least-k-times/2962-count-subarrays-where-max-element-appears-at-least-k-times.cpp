class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int freq = 0;
        int maxi = INT_MIN;
        for(auto elem:nums){
            maxi = max(maxi, elem);
        }
        long long ans = 0;
        while(r<nums.size()){
            if(nums[r] == maxi){
                freq++;
            }
            if(freq >= k){
                while(freq >= k){
                    if(nums[l]==maxi)
                        freq--;
                    l++;
                }
            }
            ans += l;
            r++;
        }
        return ans;
    }
};
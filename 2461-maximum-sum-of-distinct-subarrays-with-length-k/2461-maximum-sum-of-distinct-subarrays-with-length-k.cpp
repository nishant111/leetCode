class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        int r = k-1;
        long long sum = 0;
        for( int i = l;i<=r;i++){
            mp[nums[i]]++;
            sum += nums[i];
        }
        long long ans = 0;
        while(r<nums.size()){
            if(mp.size()==k){
                ans = max( ans, sum );
            }
            mp[nums[l]]--;
            if(mp[nums[l]] == 0){
                mp.erase(nums[l]);
            }
            sum -= nums[l];
            l++;
            r++;
            if(r<nums.size()){
                mp[nums[r]]++;
                sum += nums[r];
            }
            
        }
        return ans;
    }
};
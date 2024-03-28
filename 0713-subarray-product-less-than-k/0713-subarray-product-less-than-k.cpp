class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        int rollingProd = 1;
        while(r<nums.size()){
            rollingProd *= nums[r];
            while (rollingProd >= k){
                rollingProd = rollingProd / nums[l++];
            }
            // collect ans
            int n = r - l + 1;
            ans += n ;
            r++;
        }
        return ans;
    }
};
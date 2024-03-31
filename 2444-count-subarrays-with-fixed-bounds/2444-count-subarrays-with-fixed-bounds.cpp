class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int  l = 0;
        int r = 0;
        int lastMin = -1;
        int lastMax = -1;
        int badi = -1;
        long long ans = 0;
        while(r<nums.size()){
            if(nums[r] == minK){
                lastMin = r;
            }
            if(nums[r] == maxK){
                lastMax = r;
            }
            if(nums[r]>=minK && nums[r]<=maxK){
                // for ex 7, 1, 2, 3, 5, 2 for (minK = 2, maxk = 5)
                // badi would be 0
                // this helps include 1, 2, 3, 5 and 2, 3, 5 as 
                // min(2,4)-0, helps us obtain 2 starting positions, when r = 4
                ans += max(0, min(lastMin, lastMax)-badi);
            }
            else{
                // this is something bad
                // for ex 7, 1, 2, 3, 5, 2 for (minK = 2, maxk = 5)
                // badi = 0
                badi = r;
            }
            r++;
        }
        return ans;
    }
};
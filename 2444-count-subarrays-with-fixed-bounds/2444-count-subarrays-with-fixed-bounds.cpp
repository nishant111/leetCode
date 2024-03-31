class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int badi = -1;
        int lastMin = -1;
        int lastMax = -1;
        long long ans = 0;
        for(int i = 0;i<nums.size();i++) { 
            if(nums[i] == minK){
                lastMin = i;
            }
            if(nums[i] == maxK){
                lastMax = i;
            }

            if(nums[i] >= minK && nums[i] <= maxK)
            {
                ans += max(0,min(lastMin, lastMax)-badi);
            }
            else {
                badi = i;
            }

        }
        return ans;
    }
};
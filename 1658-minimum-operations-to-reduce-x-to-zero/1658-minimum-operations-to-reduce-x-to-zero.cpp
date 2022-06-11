class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        /* find max subarray size tmp with sum total sum - x, ans finally would be
         * nums.size()-tmp */
        
        int totalSum = 0;
        
        for(auto elem: nums)
        {
            totalSum += elem;
        }
        int targ = totalSum - x;
        if(targ<0) return -1;
        int l = 0;
        int r = 0;
        int winSum = 0;
        int maxi = INT_MIN;
        while(r<nums.size())
        {
            winSum += nums[r];
            
            if(winSum < targ)
                r++;
            else if(winSum > targ)
            {
                winSum -= nums[l++];
                winSum -= nums[r];
            }
            else // sum equal
            {
                maxi = max(maxi, r-l+1);
                r++;
            }
        }
        return (maxi == INT_MIN?-1:nums.size()-maxi);
    }
};
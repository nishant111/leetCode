class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int lcis = 1;
        int ans = 1;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                lcis++;
                if(lcis>ans)
                    ans = lcis;
            }
            else
            {
                lcis = 1;
            }
        }
        
        return ans;
        
    }
};
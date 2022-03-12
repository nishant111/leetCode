class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxYet = INT_MIN;
        int pCount = 0; //potention Count
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                pCount++;
                maxYet = max(pCount, maxYet);
            }
            if(nums[i] == 0)
            {
                //collect and decide on ans;
                maxYet = max(pCount, maxYet);
                pCount = 0;
            }
        }
        return maxYet;
    }
};
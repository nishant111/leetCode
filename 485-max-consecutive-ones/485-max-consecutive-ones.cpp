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
            }
            else
            {
                pCount = 0;
            }
            if(pCount>maxYet)
                maxYet=pCount;
        }
        return maxYet;
    }
};
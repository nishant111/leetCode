class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxYet = INT_MIN;
        int nonDup = 0;
        int i = 0;
        while(i<nums.size())
        {
            if(nums[i]>maxYet)
            {
                maxYet = nums[i];
                nums[nonDup] = nums[i];
                i++;
                nonDup++;
            }
            else
            {
                i++;
            }
        }
        return nonDup;
    }
};
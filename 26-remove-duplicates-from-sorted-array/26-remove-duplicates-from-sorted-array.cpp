class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxYet = INT_MIN;
        int nonDup = 1;
        int i = 1;
        for(;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            {
                
            }
            else if(nums[i]!=nums[i-1])
            {
                nums[nonDup] = nums[i];
                nonDup++;
            }
        }
        
        return nonDup;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                if(nums[-1 * nums[i]] < 0)
                    return -1 * nums[i];
                else
                    nums[-1 * nums[i]] = nums[-1 * nums[i]] * -1;
            }
            else{
                if(nums[nums[i]]<0) return nums[i];
                nums[nums[i]] = nums[nums[i]] * -1;
            }
        }
        return 0;
    }
};
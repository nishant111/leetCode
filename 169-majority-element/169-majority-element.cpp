class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 1;
        int ans = nums[0];
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == ans )
                vote++;
            else
            {
                vote--;
                if(vote == 0) {
                    ans = nums[i];
                    vote=1;
                }
            }
        }
        return ans;
    }
};
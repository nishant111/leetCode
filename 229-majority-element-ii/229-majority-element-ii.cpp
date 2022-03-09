class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote1 = 0;
        int vote2 = 0;
        int ans1 = 0;
        int ans2 = 0;
        vector<int> ans;
        // iterate and find two possible ans using voting.
        for(int i = 0;i<nums.size();i++)
        {
            if(ans1==nums[i] )
            {
                vote1++;
            }
            else if(ans2==nums[i])
            {
                vote2++;
            }
            else if(vote1 == 0 && nums[i]!=ans2) //init case
            {
                ans1=nums[i];
                vote1++;
            }
            else if(vote2 == 0 && nums[i]!=ans1) //init case
            {
                ans2=nums[i];
                vote2++;
            }
            else //mismatch case
            {
                vote1--;
                vote2--;
            }
        }
        // iterate and find ans out of two possible ones.
        vote1 = 0;
        vote2=0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==ans1)
            {
                vote1++;
            }
            else if(nums[i]==ans2)
            {
                vote2++;
            }
        }

        if(vote1 > (nums.size()/3) ) ans.push_back(ans1);
        if(vote2 > (nums.size()/3)) ans.push_back(ans2);
        return ans;
    }
};
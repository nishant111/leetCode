class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negCount = 0;
        int negStart = -1;
        int start = 0;
        int end = 0;
        int ans = 0;
        for(;end<nums.size();end++)
        {
            if(nums[end]<0)
            {
                if(negStart == -1)
                {
                    negStart = end;
                }
                negCount++;
            }
            if(nums[end] == 0)
            {
                negCount = 0;
                negStart = -1;
                start = end+1;
                continue;
            }
            if(negCount%2 == 0)
            {
                ans = max(ans, end - start +1 );
            }
            else
            {
                ans = max(ans, end - (negStart+1) +1);
            }
            cout<<"ans is "<<ans<<"\n";
        }
        return ans;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            //update max
            if(sum>max) max = sum;
            //if sum is neg reset
            if(sum<0) sum = 0;
        }
        return max;
    }
};
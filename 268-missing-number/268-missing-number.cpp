class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int sumArr = 0;
        int i= 0;
        for(;i<nums.size();i++)
        {
            sum += i;
            sumArr += nums[i];
        }
        sum += i;
        return (sum - sumArr);
    }
};
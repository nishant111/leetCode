class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxStreak = 0;
        int currStreak = 0;
        int maxEver = INT_MIN;
        int maxi = INT_MIN;
        
        for( int i = 0;i<nums.size();i++){
            if(nums[i]>maxi){
                // new maximum found
                currStreak = 1;
                maxi = nums[i];
                maxStreak = 0;
            }
            else if( nums[i] == maxi){
                // currStreak is incremented
                currStreak++;
            }
            else{
                // nums[i]  is less than maxi
                currStreak = 0;
            }
            maxStreak = max( maxStreak, currStreak);
        }
        return maxStreak;
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long total = 0;
        for(auto elem: nums)
        {
            total += elem;
        }
        
        sort(nums.begin(), nums.end());
        // at each i moves to equate all elements to nums[i] are
        // moves = increment moves                   +    decrement moves
        //       = (nums[i] * i) - sumbeforeNums[i]  +    sumAfterNums[i](total-sumbeforeNums[i]) - (nums[i] * (nums.length()-i) )
        
        long moves = 0;
        long ans = LONG_MAX;
        long sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            moves = ((long)nums[i] * i) - sum + (total - sum) - ((long)nums[i] * (nums.size()-i));
            
            sum += nums[i];
            
            ans = min(ans, moves); 
        }
        return ans;
    }
};
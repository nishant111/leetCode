class Solution {
public:
    int setBits( int n ){
        int count = 0;
        while(n>0){
            if( (n & 1) == 1 ){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
    
    bool canSortArray(vector<int>& nums) {
        int maxOfPrevSeg = INT_MIN;
        int minOfCurrSeg = nums[0];
        int maxOfCurrSeg = nums[0];
        int b = setBits(nums[0]);
        for( int i = 1;i<nums.size();i++ ){
            int sb = setBits( nums[i] );
            if( sb != b){
                if( minOfCurrSeg < maxOfPrevSeg )
                    return false;
                // new segment
                maxOfPrevSeg = maxOfCurrSeg;
                maxOfCurrSeg = nums[i];
                minOfCurrSeg = nums[i];
                b = setBits( nums[i] );
            }
            else{
                minOfCurrSeg = min( minOfCurrSeg, nums[i] );
                maxOfCurrSeg = max( maxOfCurrSeg, nums[i] );
            }
        }
        if( minOfCurrSeg < maxOfPrevSeg )
                    return false;
        return true;
    }
};
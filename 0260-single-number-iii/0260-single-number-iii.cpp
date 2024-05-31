class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int xorOfNumbers = 0;
        
        for(auto elem:nums){
            xorOfNumbers ^= elem;
        }
        int t=xorOfNumbers;
        int i = 0;
        while(1){
            if((t & 1) == 1){
                break;
            }
            t = t>>1;
            i++;
        }
        int mask = 1<<i;
        int nums1 = 0;
        int nums2 = 0;
        for(auto elem:nums){
            if((elem & mask)){
                nums1 ^= elem;
            }
            else{
                nums2 ^= elem;
            }
        }
        return { nums1, nums2 };
    }
};
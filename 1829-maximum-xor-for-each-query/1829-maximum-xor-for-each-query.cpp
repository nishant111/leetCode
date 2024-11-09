class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> pxor;
        pxor.push_back( nums[0] );
        
        for( int i = 1;i<nums.size();i++ ){
            pxor.push_back( pxor[pxor.size()-1] ^ nums[i] );
        }
        int mask = (1<<maximumBit)-1;
        vector<int> ans;
        for(int i = pxor.size()-1;i>=0;i--){
            ans.push_back( mask ^ pxor[i] );
        }
        return ans;
    }
};
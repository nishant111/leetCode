class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0;
        int t=nums.size()-1;
        for( int i = 0;i<=t;i++) {
            if( nums[i] == 0){
                swap( nums[i], nums[z] );
                z++;
            }
            if( nums[i] == 2){
                swap( nums[i--], nums[t--]);
            }
        }
        return;
    }
};
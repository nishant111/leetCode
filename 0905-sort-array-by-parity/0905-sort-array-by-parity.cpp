class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int e=0;
        int o=nums.size()-1;
        int i = 0;
        
        while(i<o){
            if(nums[i]%2 != 0){
                swap(nums[i],nums[o--]);
            }
            
            if(nums[i]%2 == 0){
                i++;
            }
        }
        return nums;
    }
};
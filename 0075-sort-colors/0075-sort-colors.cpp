class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size()-1;
        int i = 0;
        for(;i<=blue;i++){
            if(nums[i] == 0){
                swap(nums[i], nums[red]);
                red++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[blue]);
                i--;
                blue--;
            }
        }
        return;
    }
};
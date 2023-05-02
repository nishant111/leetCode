class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool sign = true;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == 0)
            {
                return 0;
            }
            if(nums[i]<0){
                sign=!sign;
            }
        }
        if(sign)
            return 1;
        else
            return -1;
    }
};
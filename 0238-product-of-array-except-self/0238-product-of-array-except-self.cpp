class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lpm(nums.size());
        vector<int> rpm(nums.size());
        vector<int> ans(nums.size());
        int mult = 1;
        for(int i = 0;i<nums.size();i++){
            mult = mult *nums[i];
            lpm[i] = (mult);
        }
        mult = 1;
        for(int i = nums.size()-1;i>=0;i--){
            mult = mult *nums[i];
            rpm[i] = (mult);
        }
        for(int i = 0;i<nums.size();i++){
            if(i==0){
                ans[i] = (rpm[i+1]);
            }
            else if(i==nums.size()-1){
                ans[i] = (lpm[i-1]);
            }
            else{
                ans[i] = (rpm[i+1] * lpm[i-1]);
            }
        }
        return ans;
    }
};
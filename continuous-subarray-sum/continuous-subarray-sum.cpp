/* HINT
   Try using MOD operator and checking the remainders
   */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> psum(nums.size()+1);
        psum[0] = 0;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            psum[i+1] = sum;
        }
        unordered_map<int, int> rem;
        for(int i = 0;i<psum.size();i++){
            int r = psum[i]%k;
            if(rem.find(r)!=rem.end()){
                if(i-rem[r]>1){
                    return true;
                }
                else{
                    continue;
                }
            }
            rem[r] = i;
        }
        return false;
    }
};
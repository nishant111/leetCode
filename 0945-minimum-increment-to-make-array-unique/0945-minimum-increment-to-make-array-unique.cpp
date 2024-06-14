class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        int prev = -1;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();i++){
            if(prev==nums[i]){
                nums[i]++;
                ans++;
            }
            else if(prev>nums[i]){
                ans += prev-nums[i]+1;
                nums[i]=prev+1;
            }
            prev = nums[i];
        }
        return ans;
    }
};
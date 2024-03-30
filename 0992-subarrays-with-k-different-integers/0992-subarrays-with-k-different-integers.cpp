class Solution {
public:
    int countSubArrayWithAtMostK(vector<int> &nums, int k){
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if (mp.find(nums[l]) !=mp.end() && mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }          
            ans += r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubArrayWithAtMostK (nums, k) -  countSubArrayWithAtMostK(nums, k-1);
        
    }
};
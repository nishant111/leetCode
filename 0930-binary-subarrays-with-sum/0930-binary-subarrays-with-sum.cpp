class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int ps = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ps += nums[i];
            int target = ps-goal;
            if(mp.find(target)!=mp.end()){
                ans+=mp[target];
            }
            if(ps==goal){
                ans++;
            }
            mp[ps]++;
        }
        return ans;
    }
};
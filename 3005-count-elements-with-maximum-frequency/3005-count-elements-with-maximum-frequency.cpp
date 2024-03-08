class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        int maxFreq = INT_MIN;
        unordered_map<int, int> mp;
        for(auto elem:nums){
            mp[elem]++;
            if(mp[elem]==maxFreq){
                ans += mp[elem];
            }
            else if(mp[elem]>maxFreq){
                maxFreq = mp[elem];
                ans = mp[elem];
            }
        }
        
        return ans;
    }
};
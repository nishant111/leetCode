class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        
        unordered_map<int, int> m;
        int sum = 0;
        
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            m[sum]++;
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()) ans+=m[sum-k];
        }
        
        return ans;
    }
};
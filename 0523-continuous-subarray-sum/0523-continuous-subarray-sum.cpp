class Solution {
public:
    // 23,         2,         4,    6,    7
    /* 23%6 = 5   25%6=1    29%6 = 5
    
    remainder 5 got repeated which means the elements (2+4)%6 = 0
    
    29 % n6 will always be 5
    hence, we keep finding repeated remainders with subarray         size>1 in the array
    
    */
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int psum = 0;
        for(int i =0;i<nums.size();i++)
        {
            psum += nums[i];
            if(psum % k == 0 && i>=1) return true;
            if(mp.find(psum%k)!=mp.end())
            {
                //it is a repeated remainder.
                if(i - mp[psum%k]>1) 
                    return true; // if subarray size > 1 return true
                continue;
            }
            mp[psum%k] = i;
        }
        return false;
    }
};
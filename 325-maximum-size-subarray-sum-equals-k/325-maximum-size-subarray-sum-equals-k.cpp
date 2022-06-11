class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long psum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            psum += nums[i];
            int targ = (psum-k); // as seen in example 2
            if(m.find(targ)!=m.end())
            {
                maxi = max(maxi, (i - (m[targ]+1) + 1) );
            }
            
            if(psum == k)
            {
                maxi = max(maxi, i-0+1);
            }
            if(m.find(psum)==m.end())
            {
                // maximize subarray size, if we overwrite previous index, we resuced the 
                // possible subarray size, Ex 1, 0 , -1 and k = -1;
                 m[psum] = i;
            }   
        }
        return (maxi==INT_MIN?0:maxi);
    }
};
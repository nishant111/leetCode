class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        bool rolling = 0;
        long long ans = 0;
        while(r<nums.size()) {
            if(nums[r] == 0)
            {
                if(!rolling) {
                    l=r;
                    rolling =1;
                    r++;
                }
                else {
                    r++;
                }  

            }
            else
            {
                if(rolling) {
                     long long len = (r-1) - l +1;
                    ans += (len*(len+1) * 1LL)/2LL; // sum of n consecutive no. formulae.
                    rolling = false;
                }
                r++;
            }
        }
        if(rolling)
        {
            long long len = (r-1) - l +1;
            ans += (len*(len+1) * 1LL)/2LL; // sum of n consecutive no. formulae.
            rolling = false;
        }
        return ans;
    }
};
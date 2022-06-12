#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = 0;
        unordered_set<int> s;
        int ans = INT_MIN;
        while(r<nums.size())
        {
            if(s.find(nums[r])!=s.end())
            {
                // take possible ans;
                ans = max(ans, sum);
                // shrink the window
                s.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            else
            {
                //if not found this is unique elem in this window, expand
                
                s.insert({nums[r]});
                sum += nums[r];
                r++;
            }
            
            
        }
        return max(ans, sum);
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copyNums = nums;
        sort(copyNums.begin(), copyNums.end());
        int start = -1;
        int end = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=copyNums[i])
            {
                start = i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=copyNums[i])
            {
                end = i;
                break;
            }
        }
        if(start==-1 && end == -1)
            return 0;
        else
            return end-start+1;
    }
};
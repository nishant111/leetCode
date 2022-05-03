
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                mini = min(nums[i], mini);
            }
        }
        
        for(int i = nums.size()-1;i>0;i--)
        {
            if(nums[i-1]>nums[i])
            {
                maxi = max(nums[i-1], maxi);
            }
        }
        
        int l = 0; 
        int r = nums.size()-1;
        for(;l<nums.size();l++)
        {
            if(nums[l]>mini)
            {
                break;
            }
        }
        
        for(;r>=0;r--)
        {
            if(maxi>nums[r])
            {
                break;
            }
        }
        if(l>=nums.size() && r<=0)
            return 0;
        else
            return r-l+1;
    }
};


























/*
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
*/
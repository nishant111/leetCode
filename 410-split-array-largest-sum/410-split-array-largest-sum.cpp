class Solution {
public:
    int FindSum(vector<int> nums, int i)
    {
        int sum = 0;
        while(i<nums.size())
        {
            sum += nums[i];
            i++;
        }
        return sum;
    }
    int dfs(vector<int>& nums, int part, int curr, int maxPart, int &ans)
    {
       
        if(part == maxPart && curr<nums.size())
        {
            return FindSum(nums, curr);
        }
        if(curr >= nums.size()) return -1;
        int partSum = 0;
        //int tillNow = INT_MIN;
        for(int i = curr;i<nums.size();i++)
        {
            partSum += nums[i];
            int aheadSum = dfs(nums, part+1, i+1, maxPart, ans);
            if(aheadSum == -1) break;
            int tillNow = max(partSum, aheadSum);
            ans = min(ans, tillNow);
        }
        return ans;
    }
    
    bool isSplitPossibleInM_Subarrays(vector<int> nums, int barrier, int m)
    {
        int sum = 0;
        int subArrayCount = 1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]> barrier) return false;
            if(sum + nums[i]<=barrier)
            {
                sum = sum+nums[i];
            }
            else
            {
                subArrayCount++;
                sum = nums[i];
            }
        }
        if(subArrayCount>m)
            return false;
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        //int ans = INT_MAX;
        //int rval = dfs(nums,1,0, m,ans);
        //return min(ans, rval);
        int mini = INT_MAX;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if(nums[i]<mini)
                mini = nums[i];
        }
        if(m==1) return sum;
        int left = mini;
        int right = sum;
        int ans = INT_MAX;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(isSplitPossibleInM_Subarrays(nums,mid,m))
            {
                ans = min(ans, mid);
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};
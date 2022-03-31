class Solution {
public:
    int findOcc(vector<int> nums, bool first, int target)
    {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(target>nums[mid])
            {
                l = mid+1;
            }
            else if(target < nums[mid])
            {
                r = mid-1;
            }
            else
            {
                if(first)
                {
                    if((mid-1 <0) || (nums[mid-1]!=target))
                    {
                        return mid;
                    }
                    else
                    {
                        r = mid-1;
                    }
                }
                else
                { 
                    if(mid+1==nums.size() || nums[mid+1] != target)
                    {
                        return mid;
                    }
                    else 
                    {
                        l = mid+1;
                    }
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = findOcc(nums, true, target); //first
        int lo = findOcc(nums, false, target); //last
        vector<int> ans = {fo, lo};
        return (ans);
    }
};
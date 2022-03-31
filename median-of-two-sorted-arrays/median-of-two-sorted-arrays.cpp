class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int size = (nums1.size() + nums2.size() + 1)/2;
        int left = 0;
        int right = nums1.size();
        int l1, l2, r1, r2;
        while(left<=right)
        {
            int cut1 = (left+right)/2;
            int cut2 = (size-cut1);
            
            l1 = (cut1 == 0 ? INT_MIN:nums1[cut1-1]);
            l2 = (cut2 == 0 ? INT_MIN:nums2[cut2-1]);
            
            
            r1 = (cut1 == nums1.size()?INT_MAX:nums1[cut1]);
            r2 = (cut2 == nums2.size()?INT_MAX:nums2[cut2]);
            if(l1<= r2 && l2<=r1)
            {
                if((nums1.size() + nums2.size()) % 2 == 0 )
                {
                    return ((max(l1,l2) + min(r1,r2)+0.0)/2.0);
                }
                else
                {
                    return max(l1,l2);
                }
            }
            else if(l1>r2)
            {
                right = cut1-1;
            }
            else
                left = cut1+1;
        }
        return 0;
    }
};
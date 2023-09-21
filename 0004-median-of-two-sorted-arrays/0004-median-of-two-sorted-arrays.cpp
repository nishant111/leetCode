class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int nsize = nums1.size() + nums2.size();
        int n = (nsize + 1)/2;
        int l = 0;
        int r = nums1.size();
        int l1, l2, r1, r2;
        while(l<=r)
        {
            int cut1 = (l+r)/2;
            int cut2 = n-cut1;

            l1 = cut1 == 0?INT_MIN:nums1[cut1-1];
            l2 = cut2 == 0?INT_MIN:nums2[cut2-1];

            r1 = cut1 == nums1.size()?INT_MAX:nums1[cut1];
            r2 = cut2 == nums2.size()?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2 <= r1)
            {
                if(nsize %2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)+0.0)/2.00;
                }
                else{
                    return max(l1, l2);   
                }
            }
            if(l1>r2)
            {
                r = cut1-1;
            }
            else{
                l = cut1+1;
            }
        }
        return 0;

    }
};
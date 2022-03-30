class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*if(nums1.size()>nums2.size())
            findMedianSortedArrays(nums2, nums1);
        int size = (nums1.size() + nums2.size() + 1)/2;
        int left = 0;
        int right = nums1.size();
        int l1, l2, r1, r2;
        while(left<=right)
        {
            int cut1 = (left+right)/2;
            l1 = (cut1 == 0 ? INT_MIN:nums1[cut1-1]);
            r1 = (cut1 == nums1.size()?INT_MAX:nums1[cut1]);
            int cut2 = (size-cut1);
            l2 = (cut2 == 0 ? INT_MIN:nums2[cut2-1]);
            
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
            else if(l2>r1)
            {
                left = cut1+1;
            }
            else
                right = cut1-1;
        }
        return 0;
    }*/
    if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }
};
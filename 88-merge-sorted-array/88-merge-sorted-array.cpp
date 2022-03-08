class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        m--;n--;
        
        while(i>=0)
        {
            if(m<0 || n<0) break;
            if(nums2[n]>nums1[m])
            {
                nums1[i] = nums2[n];
                n--;
                i--;
            }
            else
            {
                nums1[i] = nums1[m];
                m--;
                i--;
            }
        }
        while(i>=0)
        {
            if(n>=0)
                nums1[i] = nums2[n];
            n--;
            i--;
        }
    }
};
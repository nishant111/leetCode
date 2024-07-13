class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        //Output: [1,2,2,3,5,6]
        int curr = nums1.size()-1;
        int n1 = m-1;
        int n2 = n-1;
        
        while(n1>=0 || n2>=0){
            if(n1>=0 && n2>=0){
                nums1[curr] = nums1[n1]>=nums2[n2] ? nums1[n1--] : nums2[n2--];
            }
            else{
                if(n1>=0){
                    nums1[curr] = nums1[n1--];
                }
                else{
                    nums1[curr] = nums2[n2--];
                }
            }
            curr--;
        }
        return;
    }
};
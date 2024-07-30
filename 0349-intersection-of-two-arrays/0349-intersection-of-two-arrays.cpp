class Solution {
public:
    
    /*111233334567
    122223457
        
    123*/
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = 0;
        int n2 = 0;
        vector<int> ans;
        while(n1<nums1.size() && n2<nums2.size()){
            if(nums1[n1] == nums2[n2]) 
                ans.push_back(nums1[n1]);
            while(n1<nums1.size() && nums1[n1] == nums2[n2]){
                n1++;
            }
            if(n1 == nums1.size()) break;
            if(nums1[n1]<nums2[n2]){
                n1++;
            }
            else{
                n2++;
            }
        }
        return ans;
    }
};
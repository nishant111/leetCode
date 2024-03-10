class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st1;
        unordered_set<int> ansSet;
        for(auto elem:nums1){
            st1.insert(elem);
        }
        for(auto elem:nums2){
            if(st1.find(elem)!=st1.end() && ansSet.find(elem)==ansSet.end()){
                ans.push_back(elem);
                ansSet.insert(elem);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> n1;
        unordered_set <int> n2;
        for(auto elem:nums1){
            n1.insert(elem);
        }
        for(auto elem:nums2){
            n2.insert(elem);
        }
        vector<vector<int>> ans(2);
        for(auto elem:n1){
            if(n2.find(elem)==n2.end()){
                ans[0].push_back(elem);
            }
        }
        for(auto elem:n2){
            if(n1.find(elem)==n1.end()){
                ans[1].push_back(elem);
            }
        }
        return ans;

    }
};
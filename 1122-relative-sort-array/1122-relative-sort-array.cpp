class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(auto el:arr1){
            mp[el]++;
        }
        vector<int> ans;
        for(int i = 0;i<arr2.size();i++){
            while(mp[arr2[i]]-->0){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for(auto el:mp){
            while(el.second-->0){
                ans.push_back(el.first);
            }
        }
        return ans;
    }
};
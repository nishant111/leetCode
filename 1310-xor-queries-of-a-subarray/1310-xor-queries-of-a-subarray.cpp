class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pxor(arr.size(), 0);
        pxor[0] = arr[0];
        for(int i = 1;i<arr.size();i++){
            pxor[i] = pxor[i-1] ^ arr[i];
        }
        vector<int> ans;
        for(auto q:queries){
            int l = q[0];
            int r = q[1];
            
            if(l == 0){
                ans.push_back(pxor[r]);
            }
            else{
                ans.push_back(pxor[l-1] ^ pxor[r]);
            }
        }
        return ans;
    }
};
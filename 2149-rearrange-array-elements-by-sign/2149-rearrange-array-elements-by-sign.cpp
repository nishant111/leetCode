class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto elem:nums){
            if(elem>0){
                pos.push_back(elem);
            }
            else{
                neg.push_back(elem);
            }
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i<pos.size() || j<neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        return ans;
    }
};
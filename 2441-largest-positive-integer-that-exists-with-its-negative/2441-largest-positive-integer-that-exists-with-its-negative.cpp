class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        for(auto elem:nums){
            s.insert(elem);          
        }
        int maxi = INT_MIN;
        for(auto elem:nums){
            if(elem<0)
                continue;
            else{
                if(elem>maxi && s.find(-1 * elem)!=s.end()){
                    maxi = elem;
                }
            }
        }
        return maxi==INT_MIN?-1:maxi;
    }
};
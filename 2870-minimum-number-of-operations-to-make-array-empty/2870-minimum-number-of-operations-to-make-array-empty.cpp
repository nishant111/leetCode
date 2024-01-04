class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto elem:nums){
            mp[elem]++;
        }
        int oper = 0;
        for(auto elem:mp){
            if(elem.second % 3 == 0){
                oper += elem.second/3;
            }
            else if(elem.second % 3 == 2){
                oper += elem.second/3;
                oper++;
            }
            else if(elem.second % 3 == 1){
                if(elem.second <= 1)
                    return -1;
                else{
                    oper+= (elem.second-4)/3;
                    oper+= 2;
                }
            }
        }
        return oper;
        
    }
};
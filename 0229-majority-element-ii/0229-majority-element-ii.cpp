class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote1 = 0;
        int vote2 = 0;
        int a1 =INT_MIN;
        int a2 = INT_MIN;
        
        for(auto elem :nums){
            if(elem == a1){
                vote1++;
            }
            else if(elem == a2){
                vote2++;
            }
            else if(vote1 == 0){
                vote1++;
                a1 = elem;
            }
            else if(vote2 == 0){
                vote2++;
                a2 = elem;
            }
            else{
                vote1--;
                vote2--;
            }
        }
        vote1 = vote2 = 0;
        for(auto elem:nums){
            if(elem == a1) vote1++;
            else if(elem == a2) vote2++;
        }
        vector<int> ans;
        if(vote1>nums.size()/3)
            ans.push_back(a1);
        if(vote2>nums.size()/3)
            ans.push_back(a2);
        return ans;
    }
};
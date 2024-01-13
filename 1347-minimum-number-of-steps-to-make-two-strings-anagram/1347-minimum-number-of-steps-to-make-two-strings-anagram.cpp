class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;
        for(auto elem:s){
            sm[elem]++;
        }
        for(auto elem:t){
            tm[elem]++;
        }
        int ans =0;
        for(auto elem:tm){
            int sf = sm[elem.first];
            int tf = elem.second;
            
            if(sf>=tf)
                continue;
            else if(sf==0 && tf!=0)
            {
                ans+=tf;
            }
            else if(sf<tf){
                ans += tf-sf;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sm(26,0);
        vector<int> tm(26,0);
        
        for(auto elem:s){
            sm[elem-'a']++;
        }
        for(auto elem:t){
            tm[elem-'a']++;
        }
        
        if(sm == tm)
            return true;
        else
            return false;
    }
};
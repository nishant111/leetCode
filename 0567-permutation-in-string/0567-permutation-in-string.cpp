class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        
        unordered_map<char , int> s1m;
        for(auto elem:s1){
            s1m[elem]++;
        }

        int left = 0;
        int right = 0;
        for(;left<=s2.size()-s1.size(); left++){
            unordered_map<char , int> s2m;
            for(right=left;right < left + s1.size();right++){
                s2m[s2[right]]++;
            }
            if(s1m == s2m)
                return true;
        }
        return false;
    }
};
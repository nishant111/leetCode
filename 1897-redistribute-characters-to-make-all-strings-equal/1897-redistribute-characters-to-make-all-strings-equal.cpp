class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mp(26,0);
        for(auto elem:words){
            for(auto ch:elem){
                mp[ch-'a']++;
            }
        }
        int len = words.size();
        for(auto elem:mp){
            if(elem%len!=0)
                return false;
        }
        return true;
    }
};
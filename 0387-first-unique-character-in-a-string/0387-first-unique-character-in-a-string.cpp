class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> ss;
        
        for(auto ch:s){
            ss[ch]++;
        }
        for(int i = 0;i<s.size();i++){
            if(ss[s[i]]==1)
                return i;
        }
        return -1;
    }
};
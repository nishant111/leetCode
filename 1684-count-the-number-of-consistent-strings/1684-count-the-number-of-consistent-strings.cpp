class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allow;
        for(auto ch:allowed){
            allow.insert(ch);
        }
        int ans = 0;
        for(auto w:words){
            int i = 0;
            for(;i<w.size();i++){
                if( allow.find(w[i])==allow.end() )
                    break;
            }
            if(i == w.size())
                ans++;
        }
        return ans;
    }
};
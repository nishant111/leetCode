class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())
            return false;
        if(s.size()==t.size()){
            if(s==t)
                return true;
            return false;
        }
        
        int si = 0;
        int ti = 0;
        
        while(ti<t.size()){
            if(s[si]==t[ti]){
                si++;
            }
            ti++;
        }
        if(si==s.size())
            return true;
        return false;
    }
};
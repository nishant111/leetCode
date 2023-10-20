class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int si = s.size()-1;
        int ti = t.size()-1;
        
        while(si>=0 & ti>= 0){
            int c = 0;
            while(si>= 0){
                if(s[si]=='#'){
                    si--;
                    c++;
                }
                else if(c>0){
                    si--;
                    c--;
                }
                else break;
            }
            c = 0;
            while(ti>= 0){
                if(t[ti]=='#'){
                    ti--;
                    c++;
                }
                else if(c>0){
                    ti--;
                    c--;
                }
                else break;
            }
            if(si>=0 && ti>= 0 && s[si]!=t[ti]){
                return false;
            }
            if((si>=0) != (ti>= 0) ){
                return false;
            }
            si--;
            ti--;
            
        }
        int c=0;
        while(ti>= 0){
                if(t[ti]=='#'){
                    ti--;
                    c++;
                }
                else if(c>0){
                    ti--;
                    c--;
                }
                else break;
        }
        c=0;
        while(si>= 0){
                if(s[si]=='#'){
                    si--;
                    c++;
                }
                else if(c>0){
                    si--;
                    c--;
                }
                else break;
        }
        if(si<0 && ti<0)
            return true;
        return false;
        
    }
};
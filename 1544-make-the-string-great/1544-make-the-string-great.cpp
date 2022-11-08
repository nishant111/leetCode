class Solution {
public:
    bool satifyingBad(int i, string s)
    {
        if(s[i]==s[i+1])
            return false;
        if(s[i]!=s[i+1])
        {
            if(s[i] == s[i+1] + 'a'-'A')
                return true;
            if(s[i] == s[i+1] - ('a'-'A') )
                return true;
        }
        return false;
    }
    string makeGood(string s) {
        for(int i = 0;i<s.size()-1;i++)
        {
            if(satifyingBad(i, s))
            {
                s = s.substr(0, i) + s.substr(i+2, s.size()-i-2);
                if(i>0) i-=2;
                else i--;
            }
            
            if(s.size()==0) break;
        }
        return s;
    }
};
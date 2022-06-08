class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0) return 0;
        bool a = false;
        bool b = false;
        int lo = 0;
        int hi = s.size()-1;
        bool pali = true;
        while(lo<=hi)
        {
            if(s[lo]!=s[hi]) 
            {
                pali = false;
            }
            if(s[lo] == 'a' || s[hi] == 'a')
                a=true;
            else if(s[lo] == 'b' || s[hi] == 'b')
                b = true;
            lo++;
            hi--;
        }
        if(pali == true)
            return 1;
        else
            return 2;
    }
};
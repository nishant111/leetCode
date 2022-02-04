class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        int i = s.length()-1;
        for(;i>=0;i--)
        {
            if(s[i] == 'I')
            {
                res = res+1;
            }
            else if(s[i] == 'V')
            {
                res = res+5;
                if(i-1>=0 && s[i-1]=='I')
                {
                    res = res-1;
                    i--;
                }
                    
            }
            else if(s[i] == 'X')
            {
                res = res+10;
                if(i-1>=0 && s[i-1]=='I')
                {
                    res = res-1;
                    i--;
                }

            }
            else if(s[i] == 'L')
            {
                res = res+50;
                if(i-1>=0 && s[i-1]=='X')
                {
                    res = res-10;
                    i--;
                }
            }
            else if(s[i] == 'C')
            {
                res = res+100;
                if(i-1>=0 && s[i-1]=='X')
                {
                    res = res-10;
                    i--;
                }
            }
            else if(s[i] == 'D')
            {
                res = res+500;
                if(i-1>=0 && s[i-1]=='C')
                {
                    res = res-100;
                    i--;
                }
            }
            else if(s[i] == 'M')
            {
                res = res+1000;
                if(i-1>=0 && s[i-1]=='C')
                {
                    res = res-100;
                    i--;
                }
            }
        }
        return res;
        
    }
};
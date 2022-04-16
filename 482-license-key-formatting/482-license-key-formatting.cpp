class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int countChar = 0;
        int groupSize = 0;
        int leftOver = 0;
        int ansSize = 0;
        for(int i = 0 ;i<s.size();i++)
        {
            if ( (s[i] >= 'a' && s[i] <= 'z') ||
                 (s[i] >= 'A' && s[i] <= 'Z') ||
                 (s[i] >= '0' && s[i]<= '9')
               )
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    //convert to capital letter
                    s[i] = s[i]- 'a' + 'A';
                }
                countChar++;
            }
            
        }
        if(countChar == 0) return "";
        groupSize = k;
        leftOver = countChar%k;
        
        if(leftOver>0)
        {
            ansSize = countChar+((countChar/groupSize)-1)+1;
        }
        else
        {
            ansSize = countChar + ((countChar/groupSize)-1);
        }
        
        string ans;
        ans.resize(ansSize);
        int ansi=0;
        int si=0;
        int currentGroup = 0;
        
        if(leftOver>0)
        {
            while(ansi<leftOver)
            {
                if(s[si]=='-')
                {
                    si++;
                }
                else
                {
                    ans[ansi] = s[si];
                    ansi++;
                    si++;
                }
            }
            ans[ansi++]='-';
        }
        
        while(ansi<ansSize && si<s.size())
        {
            if(currentGroup == groupSize)
            {
                ans[ansi++] = '-';
                currentGroup = 0;
            }
            if(s[si]=='-')
            {
                si++;
            }
            else
            {
                ans[ansi] = s[si];
                currentGroup++;
                ansi++;
                si++;
                
            }
            
        }
        return ans;
        
    }
};
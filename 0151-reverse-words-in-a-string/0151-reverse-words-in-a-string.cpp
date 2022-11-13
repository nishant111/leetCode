class Solution {
public:
    string reverseWords(string s) {
        string tmp = "";
        string ans = "";
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                while(i+1<s.size() && s[i+1]==' ')
                {
                    i++;
                }
                if(s[i]==' ' && s[i+1]=='\0')break;
                if(tmp.size()>0)
                {
                    
                    ans = ' ' + tmp  +ans;
                    tmp.clear();
                }
            }
            else
            {
                tmp=tmp + s[i];
            }
        }
        ans = tmp  +ans;
        return ans;
    }
};
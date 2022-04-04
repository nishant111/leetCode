class Solution {
public:
    string dfs(string &s, int &i)
    {
        string ans = "";
        for(;i<s.length();)
        {
            if(s[i]>='1' && s[i]<='9')
            {
                int digit = 0;
                while(s[i]>='0' && s[i]<='9')
                {
                    //make digit
                    digit = digit*10 + (s[i]-'0');
                    i++;
                }
                //i is now at '['
                i++;
                string decode = dfs(s,i);
                //after returning from recursive call i should be at ']'
                i++;
                string tmp="";
                while(digit-->0)
                {
                    ans += decode;
                }
                
            }
            else if(s[i]>='a' && s[i] <='z')
            {
                ans = ans + s[i];
                i++;
            }
            else if(s[i] ==']')
            {
                return ans;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
};
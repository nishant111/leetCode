class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string ans = "";
        //odd length
        for(int i = 1;i<s.size();i++){
            int l = i-1;
            int r = i+1;
            if(1>ans.size())
                ans += s[i];
            int size = 1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                size += 2;
                if(size>ans.size())
                    ans = s.substr(l,r-l+1);
                l--;
                r++;
            }
        }
        
        //even length
        for(int i = 0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                int size = 2;
                if(size>ans.size())
                    ans = s.substr(i,2);
                int l = i-1;
                int r = i+1+1;
                while(l>=0 && r<s.size() && s[l]==s[r]){
                    size += 2;
                    if(size>ans.size())
                        ans = s.substr(l,r-l+1);
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};
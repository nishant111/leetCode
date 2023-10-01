class Solution {
public:
    void rev(string &s, int l, int r){
        while(l<=r){
            swap(s[l++], s[r--]);
        }
        return;
    }
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        
        while(r<=s.size()){
            if(r == s.size() || s[r] == ' '){
                rev(s, l, r-1);
                while(r<s.size() && s[r]==' '){
                    r++;
                }
                l = r;
                if(r==s.size()) break;
            }
            else{
                r++;
            }
        }
        return s;
        
    }
};
class Solution {
public:
    bool validPalin(string s, int l, int r, bool allowOneMismatch){
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else if(allowOneMismatch){
                if(validPalin(s, l+1, r, false) || validPalin(s, l, r-1, false)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return validPalin(s, 0, s.size()-1, true);
    }
};
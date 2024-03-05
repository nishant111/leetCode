class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;
        char chosen;
        while(l<r){
            if(s[l] == s[r]){
                chosen = s[l];
                while(l!=r && ( s[l] == chosen || s[r] == chosen ) ){
                    if(s[l]==s[r]){
                        l++;
                        r--;
                    }
                    else if(s[l]==chosen){
                        l++;
                    }
                    else if(s[r]==chosen){
                        r--;
                    }

                }
            }
            else{
                return r-l+1;
            }
        }
        if(l==r){
            if(s[r] == chosen) {
                return 0;
            }
            else
                return 1;
        }
        return l>r ? 0 : r-l+1;
    }
};
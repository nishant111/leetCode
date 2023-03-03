class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        if(h<n) return -1;
        if(h==n && haystack == needle) return 0;
        else if(h==n) return -1;
        string tmp ="";
        int l = 0;
        int r = n-1;
        tmp = haystack.substr(l, r-l+1);

        while(r<h){
            if(tmp == needle)
                return l;
            else{
                l++;
                tmp = tmp.substr(1) + haystack[++r];
            }
        }
        return -1;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.size()-1;
        while(r>= 0 && s[r]==' ')
            r--;
        int ans = 0;
        while(r>=0 && s[r]!=' '){
            ans++;
            r--;
        }
        return ans;
    }
};
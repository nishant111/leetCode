class Solution {
public:
    bool isVowel(char a){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;
        int l = 0;
        int r = 0;
        while(r<s.size()){
            if(r-l+1 <= k){
                if(isVowel(s[r])){
                    count++;
                    ans = max(ans, count);
                }
                r++;
            }
            else{
                if(isVowel(s[l])){
                    count--;
                }
                l++;
            }
        }
        return ans;
    }
};
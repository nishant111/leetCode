class Solution {
public:
    int countBinarySubstrings(string s) {
        int currCount = 1;
        int prevCount = 0;
        int ans = 0;
        for(int i = 1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans += min(currCount, prevCount);
                prevCount = currCount;
                currCount = 1;
            }
            else{
                currCount++;
            }
        }
        ans += min(currCount, prevCount);
        return ans;
    }
};
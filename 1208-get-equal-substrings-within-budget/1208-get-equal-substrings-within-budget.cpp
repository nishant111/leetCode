class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.size(), 0);
        for(int i = 0;i<s.size();i++){
            diff[i] = abs(s[i] - t[i]);
        }
        int r = 0;
        int l = 0;
        int currSum =0;
        int ans = 0;
        while(r<diff.size() && l<=r){
            currSum += diff[r];
            if (currSum <= maxCost){
                ans = max(ans, r-l +1);
                r++;
            }
            else{
                while(l<=r && currSum > maxCost){
                    currSum -= diff[l++];
                }
                ans = max(ans, r-l +1);
                r++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;
        for(auto elem:s){
            mp[elem]++;
        }
        bool oneTaken = false;
        int ans = 0;
        for(auto elem:mp){
            if(elem.second % 2 == 0){
                ans += elem.second;
            }
            else if(elem.second == 1 && !oneTaken){
                ans += 1;
                oneTaken = true;
            }
            else if(elem.second % 2 != 0){
                if(oneTaken)
                    ans += elem.second - 1;
                else{
                    ans += elem.second;
                    oneTaken=true;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k = 2;
        unordered_map <char, int> m;
        int ans = 0;
        int l = 0;
        int r = 0;
        while(l<=r && l<s.length() && r<s.length())
        {
            if(m.size()==k && m.find(s[r]) == m.end())
            {
                //first collect ans as the window is valid for now;
                ans = max(ans, r - l); //notice r is one ahead
                
                //need to release , if We aquire window has k+1 distinct
                if(m[s[l]]==1)
                    m.erase(s[l]);
                else
                    m[s[l]]-=1;
                l++;
            }
            else
            {
                //aquire
                m[s[r]] += 1;
                r++;
            }
        }
        ans = max(ans, r-l);
        return ans;
    }
};
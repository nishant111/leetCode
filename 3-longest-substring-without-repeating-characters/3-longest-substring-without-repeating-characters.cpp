class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int l = 0;
        int r = 0;
        unordered_set <char> st;
        int ans = INT_MIN;
        while(r<s.size())
        {
            if(st.find(s[r]) == st.end())
            {
                st.insert(s[r]);
                ans = max(r-l+1, ans);
                r++;
            }
            else
            {
                st.erase(s[l++]);
            }
        }
        return ans;
    }
};
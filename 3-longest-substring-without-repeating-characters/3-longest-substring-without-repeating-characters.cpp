class Solution {
public:
    // shrink or expand window based on elements in the unordered set.
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLen = 0;
        int count = 0;
        int i = 0; int j = 0;
        while(s[i]!='\0' && s[j]!='\0')
        {
            if(st.find(s[j])==st.end())
            {
                //didnt find
                st.insert(s[j]);
                count++;
                j++;
            }
            else if(st.find(s[j]) != st.end())
            {
                //found, will create duplicate start popping.
                st.erase(s[i]);
                count--;
                i++;
            }
            maxLen = max(count, maxLen);
        }
        return maxLen;
    }
};
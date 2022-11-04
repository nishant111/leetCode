class Solution {
public:
    
    unordered_set <char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left <=right)
        {
            if(st.find(s[left])!=st.end() && st.find(s[right])!=st.end())
            {
                swap(s[left++], s[right--]);
            }
            else if(st.find(s[left])==st.end())
                left++;
            else if(st.find(s[right])==st.end())
                right--;
        }
        return s;
    }
};
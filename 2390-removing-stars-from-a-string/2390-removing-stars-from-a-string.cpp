class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(auto elem:s) {
            if(elem == '*' && !st.empty())
            {
                st.pop();
            }
            else {
                st.push(elem);
            }
        }
        string ans;
        while(st.empty()!=true) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
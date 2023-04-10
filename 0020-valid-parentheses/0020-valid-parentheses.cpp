class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto elem:s) {
            if(elem == '}' || elem == ']' || elem == ')' ){
                if(st.empty())
                    return false;
                char curr = st.top();
                if(curr == '{' && elem != '}') {
                    return false;
                }
                else if (curr == '[' && elem != ']')
                    return false;
                else if(curr == '(' && elem!=')')
                    return false;
                else
                    st.pop();
            }
            else {
                st.push(elem);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto el:s){
            if(st.empty())
                st.push(el);
            else if( el == 'B' && st.top() == 'A' )
                st.pop();
            else if( el == 'D' && st.top() == 'C')
                st.pop();
            else
                st.push(el);
                
        }
        return st.size();
    }
};
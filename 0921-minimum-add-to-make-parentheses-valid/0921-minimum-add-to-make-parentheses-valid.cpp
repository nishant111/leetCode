class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto el:s){
            if( st.empty() ){
                st.push(el);
            }
            else{
                if(st.top() == '(' && el == ')' ){
                    st.pop();
                }
                else{
                    st.push(el);
                }
            }
        }
        return st.size();
    }
};
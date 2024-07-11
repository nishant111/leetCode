class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for(auto elem:s){
            if(elem==')'){
                // keep popping until '('
                string t = "";
                while(!st.empty() && st.top()!='('){
                    t += st.top();
                    st.pop();
                }
                st.pop(); //removes ( , its gurateend to be balances
                //push it back
                for(auto el:t){
                    st.push(el); 
                }
            }
            else{
                st.push(elem);
            }
            
        }
        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
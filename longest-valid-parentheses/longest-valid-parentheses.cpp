class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        
        for(int i=0;i<s.size();i++){
            char el = s[i];
            if(el == '('){
                st.push({el, i});
            }
            else{
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                }
                else{
                    st.push({el,i});
                }
                    
            }
        }
        if(st.size()==0) return s.size();
        int ans = 0;
        pair<char,int> curr = st.top();
        st.pop();
        int len = s.size()-1-(curr.second + 1) +1;
        ans = max(ans, len);
        while(!st.empty()){
            ans = max(ans, curr.second-st.top().second-1);
            curr = st.top();
            st.pop();
        }
        ans = max(ans, curr.second);
        return ans;
    }
};
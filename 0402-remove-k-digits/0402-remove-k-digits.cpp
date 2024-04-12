class Solution {
public:
    string removeKdigits(string num, int k) {
        // creating the number in a stack
        
        stack<char> st;
        
        for(auto elem:num){
            if(st.empty())
                st.push(elem);
            else{
                while(!st.empty() && (st.top()>elem) && (k>0) ){
                        st.pop();
                        k--;
                    }
                    st.push(elem);
            }
        }
        while(k>0 and !st.empty()){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        string ret = "";
        int i = 0;
        for(;i<ans.size();i++){
            if (ans[i]!='0')
                break;
        }
        for(;i<ans.size();i++){
            ret += ans[i];
        }
        return ret == "" ? "0":ret;
    }
};
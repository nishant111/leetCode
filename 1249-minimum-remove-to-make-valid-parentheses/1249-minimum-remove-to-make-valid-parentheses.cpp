class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        
        for(int i = 0;i<s.size();i++){
            char elem = s[i];
            if(elem>='a' && elem<='z')
                continue;
            if(st.empty())
                st.push({elem, i});
            else{
                if(elem == ')' ){
                    if(!st.empty() && st.top().first == '(')
                        st.pop();
                    else
                        st.push({elem, i});
                }
                else
                   st.push({elem, i});
            }
        }
        while(!st.empty()){
            auto elem = st.top();
            st.pop();
            s[elem.second]='*';
        }
        string ans="";
        for(auto elem:s){
            if(elem!='*')
                ans += elem;
        }
        return ans;
    }
};
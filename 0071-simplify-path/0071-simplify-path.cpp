class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int l =0;
        int r = 0;
        
        while(r<path.size()) {
            string curr="";
            if(path[r] == '/') {
                r++;
                while(r<path.size() && path[r] != '/'){
                    r++;
                }
                curr = path.substr(l,r-l);
            }
            cout << "curr is" << curr<<"\n";
            if(curr == "/.." && !st.empty())
            {
                st.pop();
            }
            if(curr != "/" && curr!= "/.." && curr!= "/.") {
                st.push(curr);
            }
            l=r;
        }
        if(st.empty()) return "/";
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
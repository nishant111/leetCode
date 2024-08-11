class Solution {
public:
    string getCurrElement( string& path, int& s){
        string ans = "";
        int start = s;
        while( s<path.size() && path[s]!='/'){
            ans += path[s++];
        }
        return path.substr(start, s - start);
    }
    
    string simplifyPath(string path) {
        stack<string> st;    
        for(int i = 0;i<path.size();){
             while( i<path.size() && path[i]=='/'){
                i++;
            }
            if(i == path.size()) break;
            string curr = getCurrElement( path, i );
            if(curr==".." ){
                if( !st.empty())
                    st.pop();
            }
            else if(curr=="."){
                continue;
            }
            else if(curr!="/"){
                st.push(curr);
            }
           
        }
        string ans = "";
        while(!st.empty()){
            ans = '/'+st.top() + ans;
            st.pop();
            
        }
        return ans.size()==0?"/":ans;
    }
};
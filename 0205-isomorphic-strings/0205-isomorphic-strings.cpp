class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i = 0;
        unordered_map<char, char> replaced;
        for(int i = 0;i<s.size();i++){
            if(replaced.find(s[i])==replaced.end()){
                replaced[s[i]]=t[i];
                //cout<<" replace "<<s[i]<<" with "<<t[i]<<"\n";
                s[i] = t[i];
                
            }
            else if(replaced.find(s[i])!=replaced.end()){
                //cout<<" replace "<<s[i]<<" with "<<replaced[s[i]]<<"\n";
                s[i]=replaced[s[i]];
            }
        }
        unordered_set<char> st;
        for(auto elem:replaced){
            if(st.find(elem.second)!=st.end())
                return false;
            st.insert(elem.second);
        }
        
        return s==t;
    }
};
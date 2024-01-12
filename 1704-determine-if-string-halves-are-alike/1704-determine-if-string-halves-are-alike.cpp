class Solution {
public:
    bool halvesAreAlike(string s) {
        int t1=0;
        int t2=0;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = 0;i<s.size();i++){
            char elem = s[i];
            if(i<s.size()/2 && st.find(elem)!=st.end()){
                t1++;
            }
            else if (i>=s.size()/2 && st.find(elem)!=st.end()){
                t2++;
            }
                
        }
        /*for(auto){
            if(st.find(i+'a')!=st.end()){
                if(t1[i]!=t2[i])
                    return false;
            }
        }*/
        //cout <<t1 <<" "<<t2;
        return t1==t2;
    }
};
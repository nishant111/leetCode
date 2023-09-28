class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string ans ="";
        long long len = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                len += 1;
            }
            else {
                len = len * (s[i]-'0');
            }
        }
        cout<<"len is "<<len<<"\n";
        
        int i = s.size()-1;
        while(i>=0){
            
            if(s[i]>='a' && s[i]<='z'){
                if(k==len || k ==0){
                    return ans + s[i];
                }
                len-=1;
            }
            else{
                
                len = len/(s[i]-'0');
                cout<<"len is "<<len<<"\n";
                k = k%len;
                cout<<"k is "<<k<<"\n";
            }
            
            i--;
        }
        return ans;
    }
};
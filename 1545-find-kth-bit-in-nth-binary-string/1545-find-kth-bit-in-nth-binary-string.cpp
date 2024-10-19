class Solution {
public:
    string dfs(int n){
        if(n == 1)
            return "0";
        if(n == 2)
            return "011";
        
        string t = dfs(n-1);
        
        string ret = t + "1";
        for(int i = t.size()-1;i>=0;i--){
            if(t[i] == '1'){
                ret += "0";
            }
            else{
                ret += "1";
            }
        }
        return ret;
    }
    
    char findKthBit(int n, int k) {
        string s = dfs(n);
        //cout<<s<<"\n";
        return s[k-1];
    }
};
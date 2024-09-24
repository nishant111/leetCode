class Solution {
public:
    string convert(int a){
        string ans = "";
        while(a>0){
            int digit = a%10;
            ans = char(digit+'0') + ans;
            a=a/10;
        }
        return ans;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st1;
        int ans = 0;
        for(auto el:arr1){
            string t = convert(el);
            for(int i = 0;i<t.size();i++){
                st1.insert( t.substr(0,i+1) );
            }
        }
        for(auto el:arr2){
            string t = convert(el);
            
            for(int i = 0;i<t.size();i++){
                string tofind = t.substr(0,i+1);
                if( st1.find(tofind)!=st1.end() ){
                    ans = max(ans, i+1 );
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        // odd length expansion
        string ans="";
        for(int i = 0;i<s.size();i++){
            int center = i;
            int d = 0;
            while(i-d>=0 && i+d<s.size() && s[i-d] == s[i+d]){
                d++;
            }
            d--;
            string p = s.substr(i-d, d+d+1);
            if(p.size()>ans.size()){
                ans = p;
            }
        }
        
        // even length expansion
        for(int i = 0;i<s.size()-1;i++){
            int center1 = i;
            int center2 = i+1;
            int d = 0;
            if(s[center1] == s[center2]){
                while(center1-d>=0 && center2+d<s.size() && s[center1-d] == s[center2+d]){
                    d++;
                }
                d--;
                string p = s.substr(center1-d, center2+d - (center1-d) + 1);
                if(p.size()>ans.size())
                    ans = p;
            }
        }
        
        return ans;
    }
};
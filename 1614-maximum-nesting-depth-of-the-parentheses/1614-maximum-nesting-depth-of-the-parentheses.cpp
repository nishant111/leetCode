class Solution {
public:
    int maxDepth(string s) {
        int openBrackets = 0;
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                openBrackets++;
            }
            else if(s[i] == ')'){
                ans = max(ans, openBrackets);
                openBrackets--;
            }
            else if(s[i] >= '0' && s[i] <= '9' ){
                ans = max(ans, openBrackets);
            }
            else{
                ans = max(ans, openBrackets);
            }
        }
        return ans;
    }
};
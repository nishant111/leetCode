class Solution {
public:
    bool checkValidString(string s) {
        stack<int> brackets;
        stack<int> stars;
        
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                brackets.push(i);
            }
            else if(s[i] == '*'){
                stars.push(i);
            }
            else{
                if(!brackets.empty()){
                    // if there is a corresponding open bracket use it
                    brackets.pop();
                }
                else if(!stars.empty()){
                    // otherwise, if star is available use it
                    stars.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(brackets.empty()) return true;
        
        while(!brackets.empty()){
            if(stars.empty()) return false;  // not possible to close brackets
            int bracketIdx = brackets.top();
            if(stars.top() > bracketIdx){
                // it is possible to use this star to close the pending bracket
                brackets.pop();
            }
            stars.pop();
        }
        return brackets.empty();
    }
};
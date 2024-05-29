class Solution {
public:
    int numSteps(string s) {
        int r;
        int oper = 0;
        while(s!="1"){
            r = s.size()-1;
            if(s[r] == '0'){
                s = s.substr(0, s.size()-2-0+1);
            }
            else{
                int t = r;
                while(t>=0 && s[t] == '1'){
                    s[t] = '0';
                    t--;
                }
                if(t<0){
                    s = "1" + s;
                }
                else{
                    s[t] = '1';
                }
            }
            oper++;
        }
        return oper;
    }
};
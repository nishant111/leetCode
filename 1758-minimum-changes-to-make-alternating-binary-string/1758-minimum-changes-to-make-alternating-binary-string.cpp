class Solution {
public:
    int minOperations(string s) {
        if(s.size()<=1) return 0;
        int countWay0 = 0;
        int countWay1 = 0;
        char way0 = '0';
        char way1 = '1';
        for(int i = 0;i<s.size();i++){
            if(s[i]!=way0){
                countWay0++;
            }
            if(s[i]!=way1){
                countWay1++;
            }
            char tmp = way0;
            way0=way1;
            way1 = tmp;
        }
        return min(countWay0, countWay1);
    }
};
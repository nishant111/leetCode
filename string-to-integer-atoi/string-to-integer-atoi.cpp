class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long int ret = 0;
        bool neg = false;
        while(s[i]==' ')
            i++;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+'){
            neg = false;
            i++;
        }
        while(i<s.size() && s[i] == '0'){
            i++;
        }
        while( i<s.size() && s[i] >= '0' && s[i] <= '9' ){
            ret = ret * pow(10, 1) + ( s[i] - '0' ) ;
            i++;
            if (!neg && ret>=INT_MAX)
                return INT_MAX;
            if(neg && ret*-1<=INT_MIN)
                return INT_MIN;
        }
        if(neg)
            return ret*-1;
        return ret;
        
        
    }
};
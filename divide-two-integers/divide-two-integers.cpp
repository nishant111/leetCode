class Solution {
public:
    int divide(int dividend1, int divisor1) {
        
        if(dividend1 == divisor1 ) return 1;
        if (dividend1 == INT_MIN && divisor1 == -1) return INT_MAX;
        int neg = 0;
        if(dividend1 < 0)
            neg++;
        if(divisor1<0)
            neg++;
        
        long long  dividend = abs(dividend1);
        long long divisor = abs(divisor1);
        
        if (divisor == 1) return neg==1?-dividend:dividend;
        int p = 0;
        long long ans = 0;
        while(dividend >= divisor){
            p = 0;
            while(divisor<<p+1 <= dividend){
                p++;
            }
            ans += (long long)1<<p;
            dividend -= divisor<<p;
        }
        
        if(ans == (1<<31) ){
            return neg == 1 ? INT_MIN : INT_MAX;
        }
        return neg==1?-ans:ans;
    }
};
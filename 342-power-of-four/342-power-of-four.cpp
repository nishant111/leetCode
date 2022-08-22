class Solution {
public:
    bool isPowerOfFour(int n) {
        int rem = 0;
        
        while(n>=4)
        {
            rem= n%4;
            if(rem != 0) return false;
            n = n/4;
        }
        if(n==1) return true;
        return false;
    }
};
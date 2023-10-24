class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if((n & (n-1))!=0) return false;
        int pos = 1;
        while(n>0){
            if(pos%2 == 0){
                if(n&1 == 1)
                        return false;
                    
            }
            //cout<<n<<"\n";
            n = n>>1;
            pos++;
        }
        return true;
    }
};
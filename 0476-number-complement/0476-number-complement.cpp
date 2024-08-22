class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int p = 0;
        while(num){
            if( (num & 1) == 0){
                ans = ans + pow(2, p); 
            }
            else{
                // 0 after flipping
            }
            p++;
            num = num>>1;
        }
        return ans;
    }
};
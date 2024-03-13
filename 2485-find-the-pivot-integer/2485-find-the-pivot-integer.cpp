class Solution {
public:
    int pivotInteger(int n) {
        int l = 1;
        int lsum = 1;
        int rsum = n;
        int r = n;
        while(l<r){
            if(lsum<rsum){
                l++;
                lsum += l;
            }
            else if(lsum > rsum){
                r--;
                rsum += r;
            }
            else{
                l++;
                lsum += l;
                r--;
                rsum += r;
            }
        }
        return lsum==rsum?r:-1;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int extra_close = 0;
        int maxi = INT_MIN;
        for( auto el:s ){
            if(el == '[')
                extra_close--;
            else if(el == ']')
                extra_close++;
            maxi = max(maxi, extra_close);
        }
        return (maxi+1)/2;
    }
};
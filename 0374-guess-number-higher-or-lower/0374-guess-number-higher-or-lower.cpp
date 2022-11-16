/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n==1) return 1;
        int l = 1;
        int r= n;
        long long mid;
        while(l<=r)
        {
            mid = ((long)l+(long)r)/(long)2;
            if(guess(mid) == 0){
                return mid;
            }
            else if(guess(mid)==-1)
            {
                r = mid-1;
            }
            else if(guess(mid)==1)
            {
                l=mid+1;
            }
        }
        return -1;
    }
};
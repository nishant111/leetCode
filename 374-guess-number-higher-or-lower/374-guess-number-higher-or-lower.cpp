/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
typedef unsigned int uint;
class Solution {
public:
    /* num is the guessed number
    guess(num) returns one of the three possibilities */
    int guessNumber(int n) {
         int l = 0;
         int r = n;
         int mid;
        
        while(l<=r)
        {
            mid = ((uint)l+(uint)r)/2;
            if(guess(mid) == 0)
            {
                return mid;
            }
            else if(guess(mid) == 1)
            {
                l = mid +1;
            }
            else
                r = mid -1;
        }
        return -1;
    }
};
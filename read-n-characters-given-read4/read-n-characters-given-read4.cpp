/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int remainingChars = n;
        int copiedChars = 4;
        int totalCopied = 0;
        char *iter = buf;
        while( copiedChars == 4){
            copiedChars = read4(iter);
            iter += copiedChars;
            totalCopied += copiedChars;
        }
        cout<<totalCopied;
        return min(totalCopied, n);        
        
    }
};
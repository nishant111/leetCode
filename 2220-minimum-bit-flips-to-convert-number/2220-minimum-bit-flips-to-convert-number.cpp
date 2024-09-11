class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = start ^ goal;
        int count = 0;
        while(flips>0){
            if(flips&1 == 1)
                count++;
            flips = flips>>1;
        }
        return count;
    }
};
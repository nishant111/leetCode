class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num>0) {
            int curr = num%10;
            num = num/10;
            sum += curr;
        }
        if(sum>9) sum = addDigits(sum);
        return sum;
    }
};
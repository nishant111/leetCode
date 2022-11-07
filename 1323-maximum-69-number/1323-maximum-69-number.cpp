class Solution {
public:
    int maximum69Number (int num) {
        int mynum=num;
        int ans = INT_MIN;
        int i = 0;
        int add=3;
        while(mynum>0)
        {
            if( (mynum%10)==6)
            {
                ans = max(ans, num + add);
            }
            add = add*10;
            mynum/=10;
        }
        return (ans==INT_MIN?num:ans);
        
    }
};
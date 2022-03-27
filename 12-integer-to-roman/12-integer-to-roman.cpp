#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
     string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string ans;
        for(int i = 12;i>=0;i--)
        {
            //1994/1000
            //30/1000
            int count = num/nums[i];
            if(count >0)
            {
                while(count-->0)
                {
                    ans = ans + sym[i];
                }
            }
            num = num%nums[i];
        }
        return ans;
    }
};
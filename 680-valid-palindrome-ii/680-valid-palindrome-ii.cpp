class Solution {
public:
    bool checkPalin(string s , int left , int right )
    {
         while(left<=right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
         }
        return true;
        
    }
    bool validPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        int miss = 0;
        
        while(left<=right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                if  (checkPalin(s, left+1, right) ||
                    (checkPalin(s, left, right-1)) )
                    return true;
                else
                    return false;
                    
            }
        }
        return true;
    }
};
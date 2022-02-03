

bool isPalindrome(char * s){
    char *targetS=malloc(strlen(s)+1);
    int j=0;
    for(int i = 0;i<strlen(s);i++)
    {
        if((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
        {
            if((s[i]>=65 && s[i]<=90))
            {
                targetS[j] = s[i] + 32;
                j++;
            }
            else{
            targetS[j] = s[i];
            j++;
            }
        }
           else
           continue;
        
    }
    targetS[j] = '\0';
    int right = printf("%s", targetS);
    int left=0;
    right -= 1;
    for(;left<right;left++,right--)
           {
               if(targetS[left]!=targetS[right])
               {
                   return false;
               }
           }
    return true;
}
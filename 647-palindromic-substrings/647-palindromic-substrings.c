

int countSubstrings(char * s){
    int left = 0;int right=0;
    int count = 0;
    for(int idx = 0;s[idx]!='\0';idx++)
    {   left=idx;
        right=idx;
        for(;(left>=0 && right<strlen(s));)
        {
            if(s[left]==s[right])
            {
                count++;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
        left=idx;
        right=idx+1;
        for(;(left>=0 && right<strlen(s));)
        {
            if(s[left]==s[right])
                {
                    count++;
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
        }
    }
    return count;
}
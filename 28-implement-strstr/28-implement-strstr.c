

int strStr(char * haystack, char * needle){
    int hay = 0;
    int need = 0;
    int matched = 0;
    if(strlen(needle)==0)
        return 0;
    if(strlen(haystack)==0)
        return -1;
    if(strlen(needle)>strlen(haystack))
        return -1;
    while(hay<strlen(haystack) && need<strlen(needle))
    {
        if(haystack[hay] == needle[need])
        {
            matched = 1;
            //printf("\nmatched at hay = %d and need = %d", hay, need);
            hay++;
            need++;
            
        }
        else if(haystack[hay] != needle[need] && matched == 0)
        {
            //printf("\nCouldnt match at hay=%d and need=%d", hay, need);
            hay++;
        }
        else if(haystack[hay] != needle[need] && matched == 1)
        {
            /* reset needle */
            //printf("\nresetting need to 0 and hay to %d at hay==%d and need==%d", (hay-need)+1 , hay, need);
            int val = (hay-need)+1;
            hay = val; 
            need = 0;
            matched = 0; /* reset matched as matching will restart */
            /* resetting hay is also imp, as we will restart from char where matching
             * started + 1. */
            
        }
    }
    printf("need is %d", need);
    if(need==strlen(needle))
    {
        return ((hay-1) - (need-1));
    }
    else 
    {
        return -1;
    }
}
/*

int lengthOfLongestSubstring(char * s){
    int longestTillHere= 0;
    int longestOverall = 0;
    for(int i = 0; s[i]!='\0';i++)
    {
        int hash[128]={0};
        int curr = i;
        printf("\ni is at %c",s[i]);
        longestTillHere=0;
        while(s[curr]!='\0')
        {
            //printf("\ncurr is at %c",s[curr]);
            if(hash[s[curr]] >0)
            {
                break;
            }
            else if(hash[s[curr]] == 0)
            {
                hash[s[curr]]++;
                longestTillHere++;
            }
            curr++;        
        }
        if(longestTillHere>longestOverall)
        {
            longestOverall=longestTillHere;
        }
        //printf("longest Overall is %d", longestOverall);
    }
    return longestOverall;
}*/

#define MAX(a,b) (a>=b?a:b);

int lengthOfLongestSubstring(char * s){
    int hash[128]={0};
    int left = 0;
    int right = 0;
    int res = 0;
    //hash[s[left]] += 1;
    while(s[right]!='\0')
    {
        hash[s[right]] += 1;
        if(hash[s[right]]>1)
        {
            //contract window
            while(hash[s[right]]>1)
            {
                hash[s[left]] -= 1;
                left++;
            }
        }
        res = MAX(res, right-left+1);
        right++;
    }
    return res;
}
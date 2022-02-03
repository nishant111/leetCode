

char* convert(char *s)
{
    char *res = malloc(5000);
    char *temp = res;
    printf("\n string in convert is %s",s);
    int count=1;
    //int j=0;
    int i=1;
    for(;i<strlen(s);i++)
    {
        if(s[i]==s[i-1])
        {
            count+=1;
        }
        else if(s[i]!=s[i-1])
        {
            sprintf(temp,"%d",count);
            //res[j]=count;
            //j++
            temp++;
            sprintf(temp,"%c",s[i-1]);
            //res[j]=s[i-1];
            //j++;
            temp++;
            count=1;
            //res[j]='\0';
        }
    }
    /* handle last value for ex s= '1','\0' */
    sprintf(temp,"%d",count);
    //res[j]=count;
    //j++;
    temp++;
    *temp=s[i-1];
    //j++;
    temp++;
    *temp='\0';
    free(s);
    printf("\n string in res is %s", res);
    return res;
}

char * countAndSay(int n){
    char *temp = malloc(5000);
    /* seting starting values to work on */
    temp[0]='1';
    temp[1]='\0';
    for (int i=2;i<=n;i++)
    {
        temp=convert(temp);
        printf("\ntemp is %s", temp);
        
    }
    return temp;
}
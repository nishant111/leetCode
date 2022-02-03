

int myAtoi(char * s){
    unsigned short isN=0;
    int result = 0;
    int power = 0;
    int started = 0;
    int val;
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i]==' ' && started==0)
        {
            //printf()
            continue;
        }
        else if(s[i]=='-')
        {
            isN=1;
             if(!(s[i+1]>='0' && s[i+1]<='9'))
                break;
            continue;
        }
        else if(s[i]=='+')
        {
            isN=0;
             if(!(s[i+1]>='0' && s[i+1]<='9'))
                break;
            continue;
        }
        
        else if((s[i]<48) || (s[i]>57))
        {
            printf("breaking on line 22 for i %d", i);
            break;
        }
        else if((s[i]>='0' && s[i]<='9'))
        {
            started = 1;
            val = s[i]-48; // we have the numeric in val now.
            printf("val is %d", val);
            if(result > INT_MAX/10 || (result == INT_MAX/10 && val>7))
            {
                if(isN)
                    return ((-1)*INT_MAX) - 1;
                
                else
                    printf("returning INT_MAX");
                    return INT_MAX ;
                
            }
            
            result = result*10 + val;
            if(!(s[i+1]>='0' && s[i+1]<='9'))
                break;
        }
    }
    if(isN)
        return ((-1) * result);
    else
        return result;

}
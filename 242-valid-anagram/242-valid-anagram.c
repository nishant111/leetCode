

bool isAnagram(char * s, char * t){
    int hash[26]={0};
    int i = 0;
    while(i<strlen(s))
    {
        hash[s[i]-97] += 1;
        i++;
    }
    i=0;
    while(i<strlen(t))
    {
        if(hash[t[i]-97] == 0)
        {
            return false;
        }
        else
        {
            hash[t[i]-97] -= 1;
        }
        i++;
    }
    i=0;
    while(i<26)
    {
        if(hash[i] > 0)
            return false;
        i++;
    }
    return true;
}
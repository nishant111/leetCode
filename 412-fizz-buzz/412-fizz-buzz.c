

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char **arr;
    arr= malloc(n* sizeof(char*));
    for(int i = 0;i<n;i++)
    {
        if(((i+1)%3)==0 && ((i+1)%5)==0)
        {
            *(arr+i)=malloc(strlen("FizzBuzz")+1);
            strcpy(*(arr+i), "FizzBuzz");
        }
        else if(((i+1)%3)==0)
        {
            *(arr+i)=malloc(strlen("Fizz")+1);
            strcpy(*(arr+i), "Fizz");
        }
        else if(((i+1)%5)==0)
        {
            *(arr+i)=malloc(strlen("Buzz")+1);
            strcpy(*(arr+i), "Buzz");
        }
        else
        {
            char temp[1000];
            sprintf(temp, "%d", i+1);
            *(arr+i)=malloc(strlen(temp)+1);
            strcpy(*(arr+i), temp);
        }
    }
    *returnSize = n;
    return arr;

}
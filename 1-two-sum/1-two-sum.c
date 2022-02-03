

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct mystruct_t{
    int val;
    int ind;
}mystruct;

int comp(const void *a, const void *b)
{
    return ((mystruct*)a)->val-((mystruct*)b)->val;
        
}

void printStruct(mystruct *p, int size)
{
    for(int i = 0;i<size;i++)
    {
        printf("ind is %d, value is %d\n",(p+i)->ind,(p+i)->val);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    mystruct * arr = calloc(numsSize, sizeof(mystruct));
    for(int i = 0;i<numsSize;i++)
    {
        (arr+i)->val = nums[i];
        (arr+i)->ind = i;
    }
    qsort(arr, numsSize ,sizeof(mystruct), comp);
    printStruct(arr, numsSize);
    
    int left = 0;
    int right = numsSize-1;
    int *res = calloc(2, sizeof(int));
    *returnSize =2;
    for(;left<right;)
    {
        if( ((arr+left)->val + (arr+right)->val)>target)
        {
            right--;
        }
        else if( ((arr+left)->val + (arr+right)->val)<target)
        {
            left++;
        }
        else if( ((arr+left)->val + (arr+right)->val)==target)
        {
            printf("values found are %d, %d",(arr+left)->val, (arr+right)->val );
            res[0] = (arr+left)->ind;
            res[1] = (arr+right)->ind;
            break;
        }
    }
    return res;
}
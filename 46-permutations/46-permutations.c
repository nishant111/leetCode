

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void printArray(int *arr, int size)
{
    printf("Array is \n");
    for(int i = 0;i<size;i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n\n");
}

void dfs(int * nums, int size ,int** returnColumnSizes,int ***arr, int *returnSize, int begin)
{
    if(begin == (size-1))
    {
        (*returnSize)++;
        //memleak if realloc fails arr is lost
        *arr= realloc(*arr,(*returnSize)*sizeof(int*));
        returnColumnSizes[0]= realloc(
                              returnColumnSizes[0],(*returnSize)*sizeof(int)); 
        (*arr)[(*returnSize)-1] = malloc(size* sizeof(int));
        for(int i = 0;i<size;i++)
        {
            (*arr)[(*returnSize)-1][i] = nums[i];
        }
        returnColumnSizes[0][(*returnSize)-1] = size;
        return;
    }
    
    for(int i = begin;i<size;i++)
    {
        swap(nums+begin, nums+i);
        //printArray(nums, size);
        dfs(nums, size,returnColumnSizes, arr, returnSize ,begin+1);
         swap(nums+begin, nums+i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **arr;
    *returnSize = 0;
    *returnSize = 0;
    arr = calloc(1, sizeof(int*));
    *returnColumnSizes = calloc(1, sizeof(int));
   // printf("returncolumnsize %d", )
    dfs(nums, numsSize, returnColumnSizes ,&arr, returnSize ,0);
    return arr;
}
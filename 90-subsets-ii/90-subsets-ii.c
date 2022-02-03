

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void pickOrNotPick(int *nums, int size, int ***result, int *tempSet, int *returnSize, int *tempTop ,int **rcs, int start)
{
    int done = 0;
    if(start == size)
    {
        // reached end can go no further. Save the generated array
        (*returnSize)++;
        *result = realloc(*result, sizeof(int*)*(*returnSize));
        (*result)[(*returnSize)-1] = calloc(1, sizeof(int)*((*tempTop)+1));
        *rcs = realloc(*rcs, sizeof(int)*(*returnSize));
        (*rcs)[(*returnSize-1)]=(*tempTop)+1;
        for(int i = 0;i<=(*tempTop);i++)
        {
            (*result)[(*returnSize)-1][i] = tempSet[i];
        }
        return;
    }
    else
    {
        for(int i = start;i<size && done == 0;i++)
        { 
            // picked nums[i], and recursed all possiblities
            (*tempTop)++;
            tempSet[(*tempTop)]=nums[i];
            pickOrNotPick(nums, size, result, tempSet, returnSize, tempTop, rcs, start+1);
                
            // didnt pick nums[i], and recursed all possibilites
            tempSet[(*tempTop)]=0;
            (*tempTop)--;
            //if didnt pick jump all duplicate possibilites
            while(start+1 < size && nums[start]==nums[start+1])
            {
                start++;
            }
            pickOrNotPick(nums, size, result, tempSet, returnSize, tempTop, rcs, start+1);
            done=1;
                
        }
    }
}

int comp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **arr= calloc(1, sizeof(int *));
    int *tempSet = calloc(10, sizeof(int ));
    *returnColumnSizes = calloc(1, sizeof(int));
    *returnSize = 0;
    int top = -1;
    qsort(nums, numsSize, sizeof(int), comp);
    pickOrNotPick(nums, numsSize, &arr, tempSet ,returnSize , &top,returnColumnSizes, 0);
    return arr;
}
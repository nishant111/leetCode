

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int cand1=-1;
    int cand2=-1;
    int count1=0;
    int count2=0;
    *returnSize = 0;
    for(int i = 0;i<numsSize;i++)
    {
        if(nums[i] == cand1)
        {
            count1++;
        }
        else if(nums[i] == cand2)
        {
            count2++;    
        }
        else if(count1 == 0)
        {
            cand1 = nums[i]; 
            count1++;
        }
        else if(count2 == 0)
        {
            cand2 = nums[i];
            count2++;
        }
       
        else if(nums[i] != cand1 && nums[i] != cand2)
        {
            count1--;
            count2--;
            //i--;
        }
    }
    printf("%d & %d are winners\n", cand1, cand2);
    int *arr = calloc(1, sizeof(int));
    count1 = 0;
    count2=0;
    for(int i = 0;i<numsSize;i++)
    {
        if(nums[i] == cand1)
        {
            count1++;
        }
        else if(nums[i] == cand2)
        {
            count2++;   
        }
    }
    printf("%d & %d are counts", count1, count2);
    int i = 0;
    if(count1>(numsSize/3)) 
    {
        arr[i++] = cand1;
        (*returnSize)++;
    }
    if(count2>(numsSize/3))
    {
        if(count1>(numsSize/3))
            arr = realloc(arr, sizeof(int)*2); //mem leak if realloc fails
        arr[i++] = cand2;
        (*returnSize)++;
    }
    return arr;
}
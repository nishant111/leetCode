

int findDuplicate(int* nums, int numsSize){
    
    int *hash = calloc(1, numsSize * sizeof(int));
    for(int i = 0;i<numsSize;i++)
    {
        hash[nums[i]-1] ++;
    }
    for(int i = 0;i<numsSize;i++)
    {
        if(hash[i]>1)
            return i+1;
    }
    return -1;
}
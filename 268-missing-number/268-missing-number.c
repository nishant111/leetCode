

int missingNumber(int* nums, int numsSize){
    /*
    O(n) extra space is being used
    int size = numsSize+1;
    int *hash= calloc(1,size * sizeof(int));
    for(int i = 0;i<numsSize;i++)
    {
        hash[nums[i]] += 1;
    }
    for(int i = 0;i<size;i++)
    {
        if(hash[i]==0)
            return i;
    }
    return -1;
    */
    int res=0;
    int i =0;
    for(;i<numsSize;i++)
    {
        res = res ^ i^nums[i];
    }
    res = res ^ (i);   // xor one more time as on last xor is left
    return res;
}

int compare(const void * a, const void *b)
{
    return(*(int*)a-*(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
    int find;
    qsort((void*)nums, numsSize, sizeof(int), compare);
    for(int i = 0;i+1<numsSize;i++)
    {
        if(nums[i] == nums[i+1])
            return true;
    }
    return false;

}
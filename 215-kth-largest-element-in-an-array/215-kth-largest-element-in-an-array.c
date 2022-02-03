
int comp(void *a, void *b)
{
    return (-1 * (*(int*)a - *(int *)b) );
}

int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), comp );
    return nums[k-1];
}
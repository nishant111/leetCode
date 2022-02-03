

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int* res = malloc(sizeof(int)*numsSize);
    int idx = numsSize-1;
    int start = 0;
    int end = numsSize-1;
    while(start<=end)
    {   if((nums[start]*nums[start])>=(nums[end] * nums[end]) )
        {
             res[idx] = nums[start] * nums[start];
            start++;
        }
        else if((nums[end]*nums[end])>(nums[start] * nums[start]))
        {
            res[idx] = nums[end] * nums[end];
            end--;
        }
         idx--;  
    }
    *returnSize = numsSize;
    return res;
}
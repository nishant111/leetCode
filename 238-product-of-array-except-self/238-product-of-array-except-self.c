

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int rightSum[numsSize];
    int leftSum[numsSize];
    leftSum[0]=nums[0];
    int *res = malloc(sizeof(int) * numsSize);
    rightSum[numsSize-1] = nums[numsSize-1];
    for(int i = 1;i<numsSize;i++)
    {
        leftSum[i] =leftSum[i-1] * nums[i];
    }
    for(int i = numsSize-2;i>=0;i--)
    {
        rightSum[i] =rightSum[i+1] * nums[i];
    }
    for(int i = 0;i<numsSize;i++)
    {
        if(i==0)
        {
          res[i] = rightSum[i+1];   
        }
        else if(i==numsSize-1)
        {
            res[i] = leftSum[i-1];
        }
        else
        {
            res[i] = leftSum[i-1] * rightSum[i+1];
        }
    }
    *returnSize = numsSize;
    return res;
}
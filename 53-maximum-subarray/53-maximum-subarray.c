#define MAX(a, b) ((a)>(b)?(a):(b))


int maxSubArray(int* nums, int numsSize){
    
    int bestSoFar = nums[0];
    if (numsSize == 1) return bestSoFar;
    int bestOverAll = INT_MIN;
    for(int i = 1;i<numsSize;i++)
    {
        if(bestSoFar > bestOverAll)
            bestOverAll = bestSoFar;
        bestSoFar = MAX(bestSoFar+nums[i],nums[i]);
        
        printf("\n Best So far is %d", bestSoFar);
    }
    if(bestSoFar > bestOverAll)
            bestOverAll = bestSoFar;
    return bestOverAll;

}
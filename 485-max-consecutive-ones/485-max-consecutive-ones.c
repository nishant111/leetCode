

int findMaxConsecutiveOnes(int* nums, int numsSize){

    if(numsSize == 0) return 0;
    else if(numsSize == 1 && nums[0] ==1) return 1;
    else if(numsSize == 1 && nums[0] ==0) return 0;
    int start = 0;
    int count =0;
    int end = 0;
    int totalSum = 0;
    int sumHere = 0;
    int longest = 0;
    while(end<numsSize && start < numsSize)
    {
        if(start == end && nums[start]==1)
        {
            sumHere = nums[start];
            totalSum = nums[start];
            count = 1;
            if(count > longest)
                longest = count;
            end++;
            continue;
        }
        if( (sumHere + nums[end]) == totalSum+1)
        {
            count = end-start +1;
            if(count > longest)
                longest = count;
            end++;
        }
        else 
        {
            count = 0;
            sumHere = 0;
            totalSum = 0;
            start = end+1;
            end = start;
        }
        
    }
    return longest;
}


/* awesome question for repractice */

void moveZeroes(int* nums, int numsSize){
    int iter = 0;
    int zero = 0;
    for(;iter<numsSize;)
    {
        if(nums[iter] == 0)
        {
            iter++;
        }
        else if(nums[iter]!=0)
        {
            nums[zero] = nums[iter];
            zero++;
            iter++;
        }
    }
    //zero++;
    while(zero<numsSize)
    {
        nums[zero] = 0;
        zero++;
    }
    
}


void rotate(int* nums, int numsSize, int k){
    int rotate[numsSize];
    if (k>numsSize)
        k = k%numsSize;
    int i=0;
    int ri=k;
    while (ri<numsSize)
    {
        rotate[ri] = nums[i];
        ri++;
        i++;
    }
    ri = 0;
    while(ri<k)
    {
        rotate[ri] = nums[i];
        printf("rotate[%d] is %d",ri, rotate[ri] );
        ri++;
        i++;
    }
    for(int i = 0;i<numsSize;i++)
    {
        nums[i] = rotate[i];  
    }
    //nums = &rotate;
}


int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int current = 1;
    printf("numSize is %d", numsSize);
    int unique = 0;
    while(current<numsSize)
    {
        if (nums[unique] !=nums[current])
        {
            unique++;
            nums[unique] = nums[current];
            current++;
        
        }
        else if(nums[unique] ==nums[current])
            current ++;
    }
    unique = unique+1;
    return unique;

}
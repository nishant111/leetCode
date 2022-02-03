

int search(int* nums, int numsSize, int target){
    if(numsSize == 0)
    {
        return -1;
    }
    else if(numsSize == 1)
    {
        if(nums[0] == target )
            return 0;
    }
    int left = 0;
    int right = numsSize-1;
    int mid;
    
    while(left<=right)
    {
         mid = (left+right)/2;
        if(nums[mid] == target)
            return mid;
        else if(target < nums[mid])
        {
            right = mid-1;
        }
        else if(target > nums[mid])
        {
            left = mid+1;
        }
    }
    return -1;
}
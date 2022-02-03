

int search(int* nums, int numsSize, int target){

    int start = 0;
    int end = numsSize-1;
    int mid;
    while(start < end)
    {
        mid = (start+end)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid]>=nums[start])
        {
            if(target < nums[mid] && target >= nums[start])
                end = mid-1;
            else 
                start = mid+1;
            
        }
        else if(nums[mid] < nums[start])
        {
            if(target > nums[mid] && target <= nums[end])
                start = mid +1;
            else 
                end = end -1;
        }
            
    }
    if(nums[start] == target) return start;
    else return -1;
}
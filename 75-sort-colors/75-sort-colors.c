
void swap(int *nums, int left, int right)
{
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
}

void sortColors(int* nums, int numsSize){

    int zero = 0;
    int two = numsSize-1;
    for(int i = 0;i<=two;i++)
    {
        if(nums[i] == 0)
        {
            printf("swapping %d with %d\n", nums[zero], nums[i]);
            swap(nums, zero, i);
            zero++;
        }
        else if(nums[i] == 2 )
        {
             printf("swapping %d with %d\n", nums[two], nums[i]);
            swap(nums, two, i);
            two--;i--;
        }
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int * res = malloc(2 * sizeof(int));
    int left = 0;
    //int right = left+1;
    for(;left<=numbersSize-1;left++)
    {
        int find = target - numbers[left];
        
        for(int j = left+1;j<numbersSize;j++)
        {
            if (numbers[j] == find)
            {
                res[0]=left+1;
                res[1]=j+1;
                *returnSize = 2;
                return res;
            }
        }
       /* if(numbers[left] + numbers[right] == target)
        {
            res[0]=left+1;
            res[1]=right+1;
            *returnSize = 2;
            return res;
        }
        else if(numbers[left] + numbers[right] < target)
        {
            if(right == numbersSize-1)
            {
                left++;
                right = left+1;
            }
            else
                right++;
        }*/
  
    }
    *returnSize = 0;
    return NULL;
}
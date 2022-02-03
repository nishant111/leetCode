

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **result;
    result= malloc(sizeof(int *) * numRows);
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    *returnSize = numRows;
    for(int i = 0;i<numRows;i++)
    {
        result[i] = malloc(sizeof(int) * (i+1));
        (*returnColumnSizes)[i] = i+1;
        int *temp=result[i];      // taking a direct pointer to inner array base address
        //int *tempPrev = result[i -1];
        for(int j = 0;j<i+1;j++)
        {
            if(j==0)
            {
                temp[j] = 1;
                continue;
            }
            if(j==(i))
            {
                temp[j] = 1;
                continue;
            }
            if(j>0 && j<i)
           {
                temp[j] = result[i-1][j-1] + result[i-1][j];
                continue;
           }
        }
    }
    return result;
}
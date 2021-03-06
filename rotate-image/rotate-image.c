

void reverseArr(int *arr, int len)
{
    int left = 0;
    int right = len-1;
    for(;left<=right;left++,right--)
    {
        int temp = arr[left];
        arr[left]=arr[right];
        arr[right] = temp;
    }
}


void transpose(int **matrix, int matR, int matC)
{
    for(int i = 0;i<matC;i++)
    {
        for(int j = i+1;j<matR;j++)
        {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}


void reverse(int **matrix, int matR, int matC)
{
    for(int i = 0;i<matR;i++)
    {
        reverseArr(matrix[i], matC);
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    /* easiest and effecient is to transpose and reverse rows*/
    
    transpose(matrix, matrixSize,  *matrixColSize);
    reverse(matrix, matrixSize, *matrixColSize);
    
    
    
    
    /*int left = 0;
    int right = matrixSize-1;
    int top = 0;
    int bottom = ((*matrixColSize)-1);
    int temp1;int temp2;
    for(;left<right;)
    {
        temp1 = matrix[top][right];
        matrix[top][right]=matrix[top][left];
        temp2 = matrix[bottom][right];
        matrix[bottom][right]=temp1;
        temp1 = matrix[bottom][left];
        matrix[bottom][left] = temp2;
        matrix[top][left] = temp1;
        
        left++;right--;
        top++;bottom--;
    }
    for(;left==right;)
    {
        temp1 = matrix[top][right+1];
        matrix[top][right+1] = matrix[top-1][left];
        temp2 = matrix[bottom+1][left];
        matrix[bottom+1][left] = temp1;
        temp1 = matrix[top][left-1];
        matrix[top][left-1]= temp2;
         matrix[top-1][left] = temp1;
        
        left++;right--;
    }*/
    
    

}
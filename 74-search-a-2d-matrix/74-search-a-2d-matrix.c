
bool binSearch(int *arr, int left , int right, int targ)
{
    if(left>=right) 
    {
        if(arr[left] == targ) 
            return true;
        else
            return false;
    }
    int mid = (left+right)/2;
    if(arr[mid] == targ) return true;
    if(targ<arr[mid])
        return(binSearch(arr, left, mid, targ));
    return(binSearch(arr, mid+1, right, targ));
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int found = 0;int i = 0;
    for(;i<matrixSize;i++)
    {
        if(target >= matrix[i][0] && target <= matrix[i][(*matrixColSize)-1])
        {
            found = 1;
            printf("found for row %d", i);
            break;
        }
    }
    if(found == 0) return false;
    int *arr = matrix[i];
    return (binSearch(arr, 0, (*matrixColSize)-1, target));
}
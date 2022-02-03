
void swap(char *arr, int left, int right)
{
    arr[left] = arr[left] ^ arr[right];
    arr[right] = arr[left] ^ arr[right];
    arr[left] = arr[left] ^ arr[right];
}

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize-1;
    for(;left<right;left++,right--)
    {
        swap(s, left, right);
    }
}
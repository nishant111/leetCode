
void printArr(int *nums1, int nums1Size)
{
    for(int i = 0;i<nums1Size;i++)
    {
        printf(" %d ",nums1[i]);
    }
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int first = 0;
    int second = 0;
    int mym=m;
    for(;first<nums1Size && second<nums2Size;)
    {
        //printf("nums1Size is %d\nfirst is %d\nsecond is %d\nnums1[first] is %d\nnums2[second] is %d\n", nums1Size, first, second, nums1[first], nums2[second]);
        if(nums1[first]==0 && first>=mym)
        {
            nums1[first]=nums2[second];
            first++;
            second++;
        }  
        else if(nums1[first]<=nums2[second] )
        {
            first++;
        }
        else if(nums1[first]>nums2[second])
        {
            int i = mym;
            for(;i>first;i--)
            {
                nums1[i]=nums1[i-1];
            }
            mym++;
            nums1[first]=nums2[second];
            second++;
            first++;
            /*int shiftTemp1=nums1[first];
            int shiftTemp2;
            //int shiftTemp2=nums2[j+1];
            int j=first;
            nums1[j]=0;
            for(;j<m;j++)
            {
                //shiftTemp = nums2[j+1];
                //shiftTemp1=nums1[j+1];
                printf("\nShifting\n");
                printArr(nums1, nums1Size);
                shiftTemp2=nums1[j+1];
                nums1[j+1] = shiftTemp1;
                shiftTemp1=shiftTemp2;
                
                //nums2[]
            }
            nums1[first]=nums2[second];
            second++;
            first++;*/
        }
        
        
    }
    //return nums1;

}
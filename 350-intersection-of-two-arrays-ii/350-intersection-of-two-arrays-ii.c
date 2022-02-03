

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define min(a, b) (((a) < (b)) ? (a) : (b))
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int hash1[1001]={0};
    int hash2[1001]={0};
    int i1=0;
    int i2=0;
    int *result=malloc(1001*sizeof(int));
    int idx = 0;
    while(i1<nums1Size)
    {
        hash1[nums1[i1]] += 1; 
        i1++;
    }
    while(i2<nums2Size && idx < 1001)
    {
        /*if(hash1[nums2[i2]]==0)
            continue; \/* no need to keep track if unique *\/*/
        if(hash1[nums2[i2]]>0)
        {
            //hash2[nums2[i2]] += 1; /* keep track if repeating */
            result[idx] = nums2[i2];
            hash1[nums2[i2]]-=1;
            idx++;
        }
        
        i2++;
    }
    //int fi = 0;
    //int resultidx = 0;
    /*while(fi<1000)
    {
        int min = min(hash1[fi],hash2[fi]);
        result = realloc(result, (len + min)*sizeof(int)); \/* if realloc fails then the memory leaks *\/
        len += min;
        for(;resultidx<len;resultidx++)
        {
            result[resultidx] = fi;
        }
    }*/
    *returnSize = idx;
    return result;
}
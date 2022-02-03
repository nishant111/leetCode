int hammingWeight(uint32_t n) {
    int count = 0;
    for(int i = 0;i<32;i++)
    {
        printf("\nn is %d", n);
        if((n&1)!=0)
        {
            count++;
            printf("\n incremented count");
        }
        n=n>>1;
    }
    printf("\ncount is %d", count);
    return count;
}
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long left= 1;
    long right=n;
    unsigned long long mid = (left+right)/2;
    //bool ret;
    for(;left<=right;mid=(left+right)/2)
    {
        if(isBadVersion(mid)) right=mid-1;
        else left=mid+1;
    }
    return (int)left;
    
    
}
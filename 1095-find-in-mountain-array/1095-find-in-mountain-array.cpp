/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &ma) {
        int l = 0;
        int r = ma.length()-1;
        
        while(l<r){
            int mid = (l+r)/2;
            if(ma.get(mid+1)>ma.get(mid)){
                // increasing slope
                l=mid+1;
            }
            else if(ma.get(mid-1)>ma.get(mid)){
                //falling slope
                r=mid-1;
            }
            else{
                l=mid;
                break;
            }
        }
        cout<<"peak is at "<<l<<"\n";
        int l1=0;
        int r1=l;
        while(l1<=r1){
            int mid1 = (l1+r1)/2;
            if(ma.get(mid1)==target)
                return mid1;
            else if(target>ma.get(mid1))
                l1=mid1+1;
            else
                r1=mid1-1;
        }
        l1 = l+1;
        r1 = ma.length()-1;
        while(l1<=r1){
            int mid1 = (l1+r1)/2;
            if(ma.get(mid1)==target)
                return mid1;
            else if(target>ma.get(mid1))
                r1=mid1-1;
            else
                l1=mid1+1;
        }
        return -1;
    }
};
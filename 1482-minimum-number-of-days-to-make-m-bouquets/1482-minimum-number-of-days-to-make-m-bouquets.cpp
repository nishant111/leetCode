class Solution {
public:
    int getBoq(vector<int>& bloomDay, int day, int k){
        int count = 0;
        int ans = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                count = 0;
            }
            if(count == k){
                ans++;
                count = 0;
            }
        }
        return ans;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = INT_MIN;
        for(auto el:bloomDay){
            maxi = max(maxi, el);
        }
        
        int l = 1;
        int r = maxi;
        int ans = INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            
            int n = getBoq(bloomDay, mid, k);
            if(n>=m){
                // able to make, try lesser
                ans = min(ans, mid);
                r=mid-1;
            }
            else if(n<m){
                // not able to make, try towards right
                l = mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
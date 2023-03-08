class Solution {
public:
    bool ifPossible(vector<int>& piles, int h, int barrier) {
        int currH = 0;
        for(auto elem:piles) {
            currH += elem/barrier;
            if(elem%barrier)
                currH++;
            if(currH > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right =*max_element(piles.begin(), piles.end());
        
        int ans = INT_MAX;
        while(left < right) {
            int mid = (left + right)/(long)2;
            if(ifPossible(piles, h, mid) ) {
                right = mid;
                ans = min(mid, ans);
            }
            else{
                left = mid+1;
            }
        }
        return left;
        
    }
};
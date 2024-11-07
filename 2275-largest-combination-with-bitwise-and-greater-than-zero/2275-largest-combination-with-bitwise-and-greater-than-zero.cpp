class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bc(32, 0);
        for( auto el:candidates){
            int i = 0;
            while( el>0 ){
                if( (el & 1) != 0){
                    bc[i]+=1;
                }
                el = el>>1;
                i++;
            }
        }
        int maxi = INT_MIN;
        for(auto el:bc){
            maxi = max( maxi, el );
        }
        return maxi;
    }
};
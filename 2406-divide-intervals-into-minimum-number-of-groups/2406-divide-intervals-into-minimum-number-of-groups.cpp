class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int rangeEnd = 0;
        for(auto el:intervals){
            rangeEnd = max( rangeEnd, el[1] );
        }
        
        vector<int> ptc( rangeEnd+2, 0 );
        
        for( auto el:intervals){
            ptc[el[0]]++;
            ptc[el[1]+1]--;
        }
        int overlap = 0;
        int ans = INT_MIN;
        for( int i = 0;i<=rangeEnd; i++){
            overlap += ptc[i];
            ans = max(ans, overlap);
        }
        return ans;
    }
};
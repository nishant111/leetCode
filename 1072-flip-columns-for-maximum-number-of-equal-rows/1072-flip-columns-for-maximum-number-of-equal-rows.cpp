class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        
        for( int i = 0;i<matrix.size();i++ ){
            int target = matrix[i][0];
            string t="";
            for( int j = 0;j<matrix[0].size();j++ ){
                if( matrix[i][j] == target ){
                    t+='T';
                }
                else{
                    t+='F';
                }
            }
            mp[t]++;
        }
        int ans = 0;
        for( auto el:mp){
            ans = max(ans, el.second);
        }
        return ans;
    }
};
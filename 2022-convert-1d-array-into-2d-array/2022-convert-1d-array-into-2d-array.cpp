class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int>( n, -1 ));
        int r = 0;
        int c = 0;
        int i = 0;
        for( ;i<original.size();i++){
            r = i/n;
            c = i%n;
            if(r<m && c<n)
                ans[r][c] = original[i];
            else{
                return {};
            }
        }
        if(r == m-1 && c == n-1 && i==original.size())
            return ans;
        return {};
            
    }
};
class Solution {
public:
    int findMax(int r, int c,  vector<vector<int>>& grid){
        int maxi = INT_MIN;
        for(int i=r;i<r+3;i++){
            for(int j = c;j<c+3;j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        for(int i = 0;i+2<grid.size() && i<grid.size();i++){
            for(int j = 0; j+2<grid.size() && j<grid.size();j++){
                ans[i][j] = findMax(i,j,grid);
            }
        }
        return ans;
    }
};
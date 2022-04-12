class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> tmp(m*n);
        for(int i = 0 ;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                tmp[((i*n + j)+k)%(m*n)] = grid[i][j];
            }
        }
        vector<vector<int>> ans (m, vector<int>(n));
        for(int i= 0;i<(m*n);i++)
        {
            ans[i/n][i%n] = tmp[i];
        }
        return ans;
              
    }
};
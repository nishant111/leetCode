class Solution {
public:
    void dfsIslands(vector<vector<char>>& grid, int row, int col)
    {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size()) return;
        if(grid[row][col]=='1')
        {
            grid[row][col] = '0';
            dfsIslands(grid, row+1, col);
            dfsIslands(grid, row-1, col);
            dfsIslands(grid, row, col+1);
            dfsIslands(grid, row, col-1);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[i].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    dfsIslands(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
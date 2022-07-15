class Solution {
private:
    vector<pair<int, int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r>=grid.size() || r<0 || c<0 || c>=grid[0].size() || grid[r][c]==0)
            return 0;
        grid[r][c] = 0;
        int area = 1;
        for(auto d:directions)
        {
            area += dfs(grid, r+d.first, c+d.second);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return (ans == INT_MIN?0:ans);
    }
};
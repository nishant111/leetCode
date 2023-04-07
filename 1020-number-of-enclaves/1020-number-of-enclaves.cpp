class Solution {
public:
    vector<pair<int,int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    vector<vector<bool>> vis;
    
    bool nonBoundaryWalk(vector<vector<int>>& grid, int r, int c, int &count) {
        if(r <= 0 || r>=grid.size()-1 || c<=0 || c >= grid[0].size()-1) {
            //vis[r][c] = true;
            return false;
        }
        vis[r][c] = 1;
        // explore in all directions.
        bool ret = true;
        for(auto d: dir) {
            int cr = r + d.first;
            int cc = c + d.second;
            if( grid[cr][cc] == 1 && !vis[cr][cc]) {
                count++;
                ret = ret & nonBoundaryWalk(grid, cr, cc, count);
            }
        }
        //vis[r][c] = 0;
        return ret;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        vis.resize(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int count = 1;
                    if(nonBoundaryWalk(grid, i , j, count))
                        ans += count;
                }
            }
        }
        return ans;
    }
};
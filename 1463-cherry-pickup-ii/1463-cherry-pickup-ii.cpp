typedef vector<int> v1 ;
typedef vector<v1> v2 ;
typedef vector<v2> v3 ;
class Solution {
public:
    vector<vector<int>> dir = {{+1, -1},{+1, 0},{+1, +1}};
    int dfs(vector<vector<int>>& grid, int r1r, int r1c,
            int r2r, int r2c, v3 &dp){
        if(r1c < 0 || r1c>=grid[0].size() ||
           r2c < 0 || r2c>=grid[0].size())
            return 0;
        if(r1r == grid.size()-1 && r2r == grid.size()-1){
            if(r1c == r2c)
                return grid[r1r][r1c];
            return grid[r1r][r1c] + grid[r2r][r2c];
        }
        if(dp[r1r][r1c][r2c]!=-1) return dp[r1r][r1c][r2c];
        // collect current berries
        int ans = 0;
        if(r1c == r2c){
            // only one collects if both reached same cell
            ans = grid[r1r][r1c];
        }
        else{
            ans = grid[r1r][r1c] + grid[r2r][r2c];
        }
        int count = 0;
            //both can move
            for(auto nmr1:dir){ //nmr1 => next move for robot r1
                int newr1r = r1r + nmr1[0];
                int newr1c = r1c + nmr1[1];
                for(auto nmr2:dir){ // nmr2 => next move for r2
                    int newr2r = r2r + nmr2[0];
                    int newr2c = r2c + nmr2[1];
                    count = max(count, dfs(grid, newr1r, newr1c, newr2r, newr2c, dp));
                }
            }
            ans += count;
        return dp[r1r][r1c][r2c] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        v3 dp(71,v2(71, v1(71, -1)));
        return dfs(grid, 0, 0, 0, grid[0].size()-1, dp);
    }
};
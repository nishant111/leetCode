class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int r , int c)
    {
        int gold = 0;
        int tmpr =r;
        int tmpc =c;
        int best = INT_MIN;
        if(r-1>=0 && grid[r-1][c]!= 0 && grid[r-1][c] > best)
        {
            tmpr =r;
            tmpc =c;
            best = grid[r-1][c];
            tmpr--;
        }
        if(r+1<grid.size() && grid[r+1][c] != 0 && grid[r+1][c]>best)
        {
            tmpr =r;
            tmpc =c;
            best = grid[r+1][c] ;
            tmpr++;
        }
        if(c-1>=0 && grid[r][c-1]!=0 && grid[r][c-1] > best)
        {
            tmpr =r;
            tmpc =c;
            best = grid[r][c-1];
            tmpc--;
        }
        if(c+1<grid[0].size() && grid[r][c+1]!=0 && grid[r][c+1]>best)
        {
            tmpr =r;
            tmpc =c;
            best = grid[r][c+1];
            tmpc++;
        }
        if(tmpr == r && tmpc == c) 
        {
            gold = grid[r][c]; //no movement possible
        }
        else  // try the movement and collect gold
        {
            int cache =  grid[r][c];
            grid[r][c] = 0;
            gold += (cache + dfs(grid, tmpr, tmpc));
            grid[r][c] = cache;
        }
        return gold;
    }
    
    vector<pair<int, int>>d ={ {-1,0}, {+1,0}, {0,-1}, {0,+1} };
    int dfs1(vector<vector<int>>& grid, int i , int j)
    {
        if(i<0 || i > grid.size()-1 || j<0 || j>grid[0].size()-1)
            return 0;
        if(grid[i][j]==0) return 0;
        int ans = 0;
        int cache = grid[i][j];
        grid[i][j] = 0;
        for(auto elem:d)
        {
            int tmpi = i+elem.first;
            int tmpj = j+elem.second;
            ans =  max(ans, dfs1(grid, tmpi, tmpj));
        }
        
        grid[i][j]=cache;
        return ans+cache;
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    ans = max(ans, dfs1(grid, i, j));
                }
            }
        }
        return ans;
    }
};
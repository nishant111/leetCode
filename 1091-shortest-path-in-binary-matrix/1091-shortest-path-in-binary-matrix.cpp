class Solution {
public:
    /*int dfs(vector<vector<int>>& grid, int r, int c,
           vector<vector<int>> &dp)
    {
        if(r == grid.size()-1 && c == grid[0].size()-1)
        {
            return dp[r][c] = 1;
        }
        
        if(dp[r][c]!=-1) return dp[r][c];
        
        vector<pair<int,int>> dir = {{0, 1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        int d = 10001;
        for(int i = 0;i<dir.size();i++)
        {
            if(r + dir[i].first < grid.size() && (r + dir[i].first >= 0) &&
               c + dir[i].second < grid[0].size() && (c + dir[i].second >= 0) &&
               grid[r + dir[i].first][c + dir[i].second] == 0)
            {
                grid[r][c] = 1;
                d = min(d, 1 + dfs(grid, r + dir[i].first, c + dir[i].second, dp) );
                grid[r][c] = 0;
            }
        }
        return dp[r][c]=d;
    }*/
    
    vector<pair<int, int>> getNei(vector<vector<int>>& grid, int r, int c)
    {
        vector<pair<int,int>> dir = {{0, 1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        vector<pair<int, int>> nei;
        for(int i = 0;i<dir.size();i++)
        {
            if(r + dir[i].first < grid.size() && (r + dir[i].first >= 0) &&
               c + dir[i].second < grid[0].size() && (c + dir[i].second >= 0) &&
               grid[r + dir[i].first][c + dir[i].second] == 0)
            {
                
                nei.push_back({r + dir[i].first, c + dir[i].second});
            }
        }
        return nei;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!= 0) return -1;
        
        //vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        // dfs is TLE
        // Hence do BFS for shortest paths always
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        while(q.empty()!= true)
        {
            auto curr = q.front();
            q.pop();
            if(curr.first == grid.size()-1 && curr.second == grid[0].size()-1)
            {
                return grid[curr.first][curr.second];
            }
            for(auto elem: getNei(grid, curr.first, curr.second))
            {
                grid[elem.first][elem.second] = 1+grid[curr.first][curr.second];
                q.push({elem.first, elem.second});
            }
            
        }
        return -1;
    }
};
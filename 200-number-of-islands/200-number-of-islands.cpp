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
    
    bool isValid(int row, int col, vector<vector<char>>& grid)
    {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
            return false;
        return true;
    }
    
    void bfsIslands(vector<vector<char>>& grid, int row, int col)
    {
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        while(q.empty()!=true)
        {
            cout <<"queue size is "<<q.size()<<"\n";
            auto curr = q.front();
            q.pop();
            if(isValid(curr.first + 1, curr.second, grid) && 
               grid[curr.first + 1][curr.second]=='1')
            {
                cout <<"Marking 0 for" << curr.first+1 <<" "<< curr.second<<"\n";
                grid[curr.first+1][curr.second] = '0';
                q.push({curr.first + 1, curr.second});
            }
            if(isValid(curr.first - 1, curr.second, grid)  && 
               grid[curr.first - 1][curr.second]=='1' )
            {
                cout <<"Marking 0 for" << curr.first-1 <<" "<< curr.second<<"\n";
                grid[curr.first][curr.second-1] = '0';
                q.push({curr.first - 1, curr.second}) ;
            }
            if(isValid(curr.first, curr.second + 1, grid) && 
               grid[curr.first][curr.second+1]=='1' )
            {
                cout <<"Marking 0 for" << curr.first <<" "<< curr.second+1<<"\n";
                grid[curr.first][curr.second+1] = '0';
                q.push({curr.first, curr.second+1});
            }
            if(isValid(curr.first, curr.second-1, grid) && 
               grid[curr.first][curr.second-1]=='1' )
            {
                cout <<"Marking 0 for" << curr.first <<" "<< curr.second-1<<"\n";
                grid[curr.first][curr.second-1] = '0';
                q.push({curr.first, curr.second-1});
            }
        }
    }
    
    void dfsLatest(vector<vector<char>>& grid, int row, int col, int &count)
    {
        cout <<"in dfs";
        if(col >= grid[0].size() || row >= grid.size() || row<0 || col < 0)
            return ;
        if(grid[row][col] == '1')
        {
            cout <<"marking 0";
            grid[row][col]='0';
            dfsLatest(grid, row+1, col, count);
            dfsLatest(grid, row-1, col, count);
            dfsLatest(grid, row, col+1, count);
            dfsLatest(grid, row, col-1, count);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    dfsLatest(grid, i, j, count);
                    count++;
                    cout<<"incrementing count";
                }
            }
        }
        return count;
    }
    int numIslands1(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[i].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    //dfsIslands(grid, i, j);
                    bfsIslands(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
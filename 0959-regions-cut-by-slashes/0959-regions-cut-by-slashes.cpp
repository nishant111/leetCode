class Solution {
public:
    void expandGrid(vector<string>& grid, int rows, int cols,  vector<vector<int>>& mygrid){
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                int baserow = i*3;
                int basecol = j*3;
                if(grid[i][j] == '/'){
                   mygrid[baserow][basecol+2]=1;
                   mygrid[baserow+1][basecol+1]=1;
                   mygrid[baserow+2][basecol]=1;
                }
                else if(grid[i][j] == '\\'){
                    mygrid[baserow][basecol]=1;
                    mygrid[baserow+1][basecol+1]=1;
                    mygrid[baserow+2][basecol+2]=1;
                }
            }
        }
    }
    
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1},{1, 0}};
    void dfs( vector<vector<int>>& mygrid, int r, int c){
        mygrid[r][c] = 1;
        for(auto d:dir){
            int newr = r+d[0];
            int newc = c+d[1];
            if(newr<0 || newc <0 || newr >= mygrid.size() || newc >= mygrid[0].size() || mygrid[newr][newc] == 1)
                continue;
            else{
                // in bound
                dfs( mygrid, newr, newc);
            }
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> mygrid( rows * 3, vector<int>(cols*3, 0));
        
        expandGrid( grid, rows, cols, mygrid);
        //vector<vector<bool>> vis( rows * 3, vector<int>(cols*3, false));
        int count = 0;
        for(int i=0;i<mygrid.size();i++){
            for(int j = 0;j<mygrid[0].size();j++){
                if( mygrid[i][j] == 0){
                    dfs( mygrid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
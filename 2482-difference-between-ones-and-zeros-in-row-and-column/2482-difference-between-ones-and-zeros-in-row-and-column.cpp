class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> rowone;
        unordered_map<int, int> colone;
        unordered_map<int, int> rowzero;
        unordered_map<int, int> colzero;
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    rowone[i]++;
                    colone[j]++;
                }
                if(grid[i][j]==0){
                    rowzero[i]++;
                    colzero[j]++;
                }
            }
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                grid[i][j] = rowone[i] + colone[j]- rowzero[i]-colzero[j];
            }
        }
        return grid;
    }
        
};
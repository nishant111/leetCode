class Solution {
public:
    void dfs(vector<vector<int>> & matrix, int curr, int row, int col, char dir)
    {
        if(row <0 || col < 0 || row>=matrix.size() || col>=matrix.size())
        {
            return;
        }
        
        if(matrix[row][col]!=0) return; //already filled;
        
        matrix[row][col] = curr;
        
        if(dir=='u')
        {
            dfs(matrix, curr+1, row-1, col, 'u');
        }
        
        dfs(matrix, curr+1, row, col+1, 'r');
        dfs(matrix, curr+1, row+1, col, 'd');
        dfs(matrix, curr+1, row, col-1, 'l');
        dfs(matrix, curr+1, row-1, col, 'u');
        
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n,vector<int>(n, 0));
        dfs(matrix, 1, 0, 0, 'r');
        return matrix;
    }
};
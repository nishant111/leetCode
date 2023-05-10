class Solution {
public:
    void dfs( vector<vector<int>>&mat, int r, int c, char dir, int curr) {
        if(r<0 || c<0||r>=mat.size()||c>=mat[0].size()){
            return;
        }
        if(mat[r][c]!=0) return; //already filled
        mat[r][c] = curr;
        if(dir=='u'){
            dfs(mat, r-1, c, 'u', curr+1);
        }

        dfs(mat, r, c+1, 'r', curr+1);
        dfs(mat, r+1, c, 'd', curr+1);
        dfs(mat, r, c-1, 'l', curr+1);
        dfs(mat, r-1, c, 'u', curr+1);
        return;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n,0));

        dfs(mat, 0, 0, 'r', 1);
        return mat;
    }
};
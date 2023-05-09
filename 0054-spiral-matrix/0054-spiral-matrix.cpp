class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int r, int c, vector<int>&ans, char dir ){
        if(r<0||c<0||r>=matrix.size()||c>=matrix[0].size())
        {
            return;
        }
        if(matrix[r][c]==-101) return;
        ans.push_back(matrix[r][c]);
        matrix[r][c]=-101;
        if(dir=='u'){
            dfs(matrix, r-1, c, ans, 'u');
        }

        dfs(matrix, r, c+1, ans, 'r');
        dfs(matrix, r+1, c, ans, 'd');
        dfs(matrix, r, c-1, ans, 'l');
        dfs(matrix, r-1, c, ans, 'u');
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        dfs(matrix, 0, 0, ans, 'r');
        return ans;
    }
};
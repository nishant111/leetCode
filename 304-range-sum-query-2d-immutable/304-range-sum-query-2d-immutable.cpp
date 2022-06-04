class NumMatrix {
public:
    vector<vector<int>> mymatrix;
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()+1, 0));
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                dp[i][j+1] = dp[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1;i<(row2)+1;i++)
        {
            // dp[row1][col2+1] is for elements from  row1,0 to row1,col2
            sum +=  (dp[i][col2+1] - dp[i][col1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
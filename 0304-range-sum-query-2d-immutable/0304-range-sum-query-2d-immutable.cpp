class NumMatrix {
public:
    vector<vector<int>> psum;
    NumMatrix(vector<vector<int>>& matrix) {
        psum = vector<vector<int>>(matrix.size(),vector<int> (matrix[0].size(),0));
        
        for(int i = 0;i<matrix.size();i++){
            int rowSum = 0;
            for(int j = 0;j<matrix[0].size();j++){
                rowSum += matrix[i][j];
                int rowAbove = i-1>=0?psum[i-1][j]:0;
                psum[i][j] = rowSum + rowAbove;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomRight = psum[row2][col2];
        int top = 0;
        int left = 0;
        int common = 0;
        if(row1-1>=0)
            top = psum[row1-1][col2];
        if(col1-1>=0)
            left = psum[row2][col1-1];
        if(row1-1>=0 && col1-1>=0)
            common = psum[row1-1][col1-1];
        return bottomRight - ( top + left ) + common; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
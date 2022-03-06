class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> cpmatrix;
        int m = matrix.size();
        int n = matrix[0].size();
        bool col0 = false;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(j==0 && matrix[i][j] == 0)
                {
                    col0 = true;
                    continue;
                }
                if(matrix[i][j] == 0)
                {
                    //mark dummy array
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
                
            }
        }
        
        
        
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=1;j--)
            {
                
                if(matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
                if(matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
                
            }
            if( col0 == true)
            {
                    matrix[i][0] = 0;
                    continue;
            }
        }
    }
};
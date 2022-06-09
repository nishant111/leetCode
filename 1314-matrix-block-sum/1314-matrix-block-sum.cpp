class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pcolSum(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0)
                {
                    pcolSum[i][j] = mat[i][j];
                }
                else
                {
                    pcolSum[i][j] = pcolSum[i-1][j] + mat[i][j];
                }
            }
        }
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int rs = max(0, i-k); //row start
                int re = min(m-1, i+k); //row end
                int cs = max(0, j-k); //col start
                int ce = min(n-1, j+k); // col end
                
                for(int q = cs;q<=ce;q++)
                {
                    ans[i][j] += pcolSum[re][q];
                }
                
                if(rs>0) //need to subtract row1 for 7, 8, 9.
                {
                    for(int u = cs;u<=ce;u++)
                    {
                        ans[i][j] -= pcolSum[rs-1][u];
                    }
                }
            }
        }
        return ans;
    }
};
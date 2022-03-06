class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        
        for(int i = 1;i<=numRows;i++)
        {
            for(int j = 0;j<i;j++)
            {
                int row = i-1;
                if(j==0)
                    tri[row].push_back(1);
                else if(j==row)
                    tri[row].push_back(1);
                else
                {
                    tri[row].push_back(tri[row-1][j-1] + tri[row-1][j]);
                }
            }
        }
        return tri;
    }
};
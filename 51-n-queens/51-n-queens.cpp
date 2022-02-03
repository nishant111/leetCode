class Solution {
private:
    bool checkQueens(vector<string> temp, int row, int col, int size)
    {
        // check staright up
        for(int i = row;i>=0;i--)
        {
            if(temp[i][col] == 'Q')
                return false;
        }
        //check diagnol left
        for(int i = row, j=col;i>=0 && j>=0;i--,j--)
        {
            if(temp[i][j] == 'Q')
                return false;
        } 
        //check diagnol right
        for(int i = row, j=col;i>=0 && j<size; i--,j++)
        {
            if(temp[i][j] == 'Q')
                return false;
        }
        return true;
            
    }
    void dfs(int curr,vector <vector<string>> &res, vector <string> temp, int size)
    {
        if(curr == size)
        {
            res.push_back(temp);
            return;
        }
        else
        {
            for(int col = 0;col<size;col++)
            {
                if(checkQueens(temp, curr, col, size))
                {
                    temp[curr][col] = 'Q';
                    dfs(curr+1, res, temp, size);
                    temp[curr][col] = '.';
                }
                
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        char *s = (char*)calloc(n+1, sizeof(char));
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                s[j] = '.';
            temp.push_back(s);
        }
        vector <vector<string>> res;
        dfs(0,res, temp, n);
        return res;
    }
};
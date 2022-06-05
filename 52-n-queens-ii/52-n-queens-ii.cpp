

class Solution {
public:
    bool canPlaceQueen(vector<string> &board, int row, int col, int n)
    {
        int origRow = row;
        int origCol = col;
        //left diag
        while(row>=0 && col >=0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;col--;
        }
        row=origRow; col=origCol;
        //right diag;
        while(row>=0 && col<n)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row--;col++;
        }
        row = origRow; col = origCol;
        //straight up
        while(row>= 0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row--;
        }
        return true;
    }
    void dfs(vector<string> &board, int curr, int &count)
    {
        if(curr==board.size())
        {
            count++;
            return;
        }
        
        for(int i = 0;i<board.size();i++)
        {
            if(canPlaceQueen(board, curr, i, board.size()))
            {
                board[curr][i] = 'Q';
                dfs(board, curr+1, count);
                board[curr][i] = '.';
            }
        }
        
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board;
        string s ="";
        for(int i = 0;i<n;i++)
        {
            s.push_back('.');
        }
        for(int i = 0;i<n;i++)
        {
            board.push_back(s);
        }
        dfs(board, 0, count);
        return count;
    }
};



























/*class Solution {
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
};*/
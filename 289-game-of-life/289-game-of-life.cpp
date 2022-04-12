class Solution {
public:
    int countLiveNeighbours(vector<vector<int>>&  board, int row, int col)
    {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        if(row+1 <m && board[row+1][col]==1) count++;
        if(row+1 <m && col-1 >= 0 && board[row+1][col-1]==1) count++;
        if(col -1 >= 0 && board[row][col-1]==1) count++;
        if(row-1 >=0 && col-1 >=0 && board[row-1][col-1]==1) count++;
        if(row-1 >=0 && board[row-1][col]==1) count++;
        if(col+1 <n && row-1>=0 && board[row-1][col+1]==1) count++;
        if(col+1 <n && board[row][col+1]==1) count++;
        if(row+1 <m && col+1 <n && board[row+1][col+1]==1) count++;
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m, vector<int> (n));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int nei = countLiveNeighbours(board, i, j);
                if(nei == 3 || nei == 2)
                {
                    if(board[i][j]==1)
                        ans[i][j] = 1;
                    else if(board[i][j]==0 && nei == 3)
                        ans[i][j] = 1;
                }
                else if(nei > 3)
                {
                    ans[i][j] = 0;
                }
                else if(nei<2)
                {
                    ans[i][j]=0;
                }
            }
        }
        board = ans;
        
    }
};
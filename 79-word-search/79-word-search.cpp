class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,
             int row, int col, int wi)
    {
        if(row<0||row>=board.size()||col<0||col>=board[0].size())
            return false;
        if(wi == word.length()-1)
            return true;
        if(row+1<board.size() && board[row+1][col] == word[wi+1])
        {
            char tmp = board[row][col];
            board[row][col]='\0';
            if(dfs(board, word, row+1, col, wi+1))
            {
                return true;
            }
            board[row][col]=tmp;
        }
        if(col+1<board[0].size() && board[row][col+1] == word[wi+1]
          )
        {
            char tmp = board[row][col];
            board[row][col]='\0';
            if(dfs(board, word, row, col+1, wi+1))
            {
                return true;
            }
           board[row][col]=tmp;
        }
        if(row-1<board.size() && board[row-1][col] == word[wi+1]
          )
        {
            char tmp = board[row][col];
            board[row][col]='\0';
            if(dfs(board, word, row-1, col, wi+1))
            {
                return true;
            }
            board[row][col]=tmp;
        }
        if(col-1<board[0].size() && board[row][col-1] == word[wi+1]
          )
        {
            char tmp = board[row][col];
            board[row][col]='\0';
            if(dfs(board, word, row, col-1, wi+1))
            {
                return true;
            }
            board[row][col]=tmp;
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
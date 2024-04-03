class Solution {
public:
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool oob(int r,int c,vector<vector<char>>& board)
    {
        if(r<0 || r>= board.size() || c<0 || c>=board[0].size())
            return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, int r, int c, string word, int curr){
        if(oob(r,c, board))
            return false;
        if(curr == word.size())
            return true;
        
        for(auto elem:dir)
        {
            int newr = r+ elem.first;
            int newc = c+ elem.second;
            if(!oob(newr,newc,board) && board[newr][newc] == word[curr])
            {
                char tmp = board[newr][newc];
                board[newr][newc] = '\0';
                if(dfs(board, newr, newc, word, curr+1))
                    return true;
                board[newr][newc]=tmp;
            }
        }
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    char tmp = board[i][j];
                    board[i][j] = '\0';
                    if(dfs(board, i, j, word, 1))
                       return true;
                    board[i][j] = tmp;
                }
            }
        }
        return false;
    }
};
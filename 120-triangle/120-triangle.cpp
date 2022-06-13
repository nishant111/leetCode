/*class Solution {
public:
    //int dp[201][201];
    int dfs(int r, int c,vector<vector<int>> triangle, vector<vector<int>> &dp)
    {
        // think of base case
        if(r==triangle.size()-1)
        {
            return dp[r][c] = triangle[r][c];
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 0;
        
        ans = triangle[r][c] + min(dfs(r+1, c, triangle, dp), dfs(r+1, c+1, triangle, dp));
        return dp[r][c] = ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        int ans =  dfs(0, 0, triangle, dp);
        return ans;
    }
};



*/

























class Solution {
public:
    int count=0;
    int dfs(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp)
    {
        count++;
        if(row == triangle.size()-1) return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int down = triangle[row][col] + dfs(triangle, row+1,col,dp);
        int diag = triangle[row][col] + dfs(triangle, row+1,col+1,dp);
        return dp[row][col]= min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        int ans =  dfs(triangle, 0 , 0,dp);
        cout << "count is"<<count;
        return ans;
    }
};





int dfs(int currrow, int currcol, int m , int n, int **dp)
{
    if(currrow == m-1 && currcol == n-1)
    {
        dp[currrow][currcol] = 1;
        return 1;
    }
    if(currrow >=m || currcol >= n)
    {
        return 0;
    }
    // move down
    if(dp[currrow][currcol]!=0)
    {
        return dp[currrow][currcol];
    }
    dp[currrow][currcol] = 
        dfs(currrow+1, currcol, m, n, dp) +
        dfs(currrow, currcol + 1, m , n, dp);
    return dp[currrow][currcol];
}

int uniquePaths(int m, int n)
{
    int count = 0;
    int** dp= calloc(m, sizeof(int*));
    for(int i = 0;i<m;i++)
    {
        dp[i]=calloc(n, sizeof(int));
    }
    dfs(0, 0, m, n, dp);
    return dp[0][0];
}
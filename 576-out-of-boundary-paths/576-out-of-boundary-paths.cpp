typedef vector<int> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;
class Solution {
public:
    
    vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int dfs(int m, int n, int maxMove, int startRow, int startColumn, v3 &dp) 
    {
        //dfs(m, n, maxMove, startRow, startColumn);
        if((startRow >= m || startRow<0 || startColumn<0 || startColumn>=n) && (maxMove >=0) )
        {
            return 1;
        }
        else if(maxMove == 0 && !(startRow >= m || startRow<0 || startColumn<0 || startColumn>=n))
       {
           return 0;
       }
        if(dp[startRow][startColumn][maxMove]!= -1) return dp[startRow][startColumn][maxMove];
        long long ans = 0;
        for(auto d: directions)
        {
            ans += dfs(m, n, maxMove-1, startRow+d.first, startColumn+d.second, dp);
        }
        return dp[startRow][startColumn][maxMove] = ans%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        v3 dp(m, v2(n, v1(maxMove+1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, dp);
    }
};
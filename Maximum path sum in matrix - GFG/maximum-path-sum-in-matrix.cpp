// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(vector<vector<int>> &mat, int row, int col, int N, vector<vector<int>>&dp)
    {
        if(row>N-1 || col>N-1 || col<0) return INT_MIN;
        if(row == N-1) return mat[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int down = 0;
        int downl = 0;
        int downr = 0;
            down = mat[row][col] + dfs(mat, row+1, col, N, dp);
                downl= mat[row][col] + dfs(mat, row+1, col+1, N, dp);
                downr= mat[row][col] + dfs(mat, row+1, col-1, N, dp);
        return dp[row][col] = max(downr, max(down, downl));
        
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int sum = INT_MIN;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        // code here
        for(int i = 0;i<N;i++)
        {
            int tmp = dfs(Matrix, 0, i, N, dp);
            if(tmp>sum)
                sum = tmp;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
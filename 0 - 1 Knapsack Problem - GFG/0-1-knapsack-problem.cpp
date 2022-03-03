// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int dfs(int capacity, int wt[], int val[], int n, int curr,
            vector<vector<int>>& dp)
    {
        
        if(capacity < 0 )
        {
            //invalid selection
            return INT_MIN;
        }
        if(capacity == 0 || curr >= n)
        {
            //might be an answer
            return 0;
        }
        if(dp[capacity][curr] != -1) return dp[capacity][curr];
        
        int pickProfit = val[curr] + dfs(capacity - wt[curr], wt, val, n, curr+1, dp); 
        int nonpickProfit = dfs(capacity, wt, val, n, curr+1, dp);
        return dp[capacity][curr] = max(pickProfit, nonpickProfit);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int curr = 0;
       vector<vector<int>> dp (W+1, vector<int>(n+1, -1));
       return dfs(W, wt, val, n, curr, dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
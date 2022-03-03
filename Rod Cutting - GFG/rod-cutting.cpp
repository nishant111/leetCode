// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dfs(vector<int> &priceV, int rem,
            vector<int> &dp)
    {
        if(rem==0){
            //no more cuts allowed further
            return 0;
        }
        if(dp[rem]!=-1) return dp[rem];
        int profit = INT_MIN;
        for(int i = 1;i<=priceV.size();i++)
        {
            //cut at i and check further possibilities
            if(rem-i>=0)
            {
                profit =max(profit, priceV[i-1] + dfs(priceV, rem-i,dp));
            }
            
        }
        return dp[rem] = profit;
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> priceV(price, price+n);
        vector<int> dp(n+1, -1);
        return dfs(priceV, n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
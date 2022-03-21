// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //start summing while iterating ans push in a hash map sum=>idx
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map <int, int> m;
        int sum = 0;
        int maxcount = 0;
        for(int i = 0;i<n;i++)
        {
            int count = 0;
            sum += A[i];
            if(sum == 0)
            {
                count = i+1;
            }
            else if(m.find(sum) == m.end())
            {
                m.insert({sum, i});
            }
            else if(m.find(sum)!=m.end())
            {
                // there exist a sum already. currentidx - sum=> idx is the req len
                count = i - m[sum];
            }
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
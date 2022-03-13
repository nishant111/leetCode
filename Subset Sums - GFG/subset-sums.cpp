// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void dfs(vector<int> &arr, vector<int> &sum , 
            int curr, int currsum)
    {
        if(curr >= arr.size())
        {
            sum.push_back(currsum);
            return;
        }
        
        dfs(arr, sum, curr+1, currsum + arr[curr]);
        dfs(arr, sum, curr+1, currsum);
        return;
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sum;
        dfs(arr, sum, 0, 0);
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
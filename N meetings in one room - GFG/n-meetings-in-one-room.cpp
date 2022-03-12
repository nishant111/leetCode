// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    static int compare(const pair<int, int> &a, const pair<int, int>&b)
    {
        return a.second<b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meetings;
        for(int i = 0;i<n;i++)
        {
            pair<int, int> elem = {start[i], end[i]};
            meetings.push_back(elem);
        }
        sort(meetings.begin(), meetings.end(), compare);
        int count = 0;
        int endTime = -1;
        for(int i = 0;i<n;i++)
        {
            if(meetings[i].first>endTime)
            {
                endTime = meetings[i].second;
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
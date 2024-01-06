class Solution {
public:
    static bool comp(vector<int>& A, vector<int>& B){
        return(A[0]<B[0]);
    }
    
    int dfs(vector<vector<int>>& arr, int curr, vector<int>& dp){
        if(curr >= arr.size())
            return 0;
        if (dp[curr]!=-1) return dp[curr];
        int ti = curr;
        //while(ti<arr.size() && arr[ti][0]<arr[curr][1])
        //    ti++;
        // find first item in arr whose startTime >= endTime of arr[curr]
        int l = curr+1;
        int r = arr.size()-1;
        int targ = arr[curr][1];
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid][0]==targ){
                r = mid-1;
            }
            else if(arr[mid][0]<targ){
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        int pick = arr[curr][2]+dfs(arr, l, dp);
        int np = dfs(arr, curr+1, dp);
        return dp[curr] = max(pick , np);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> arr;
        vector<int> dp(startTime.size()+1, -1);
        for(int i = 0;i<startTime.size();i++){
            vector<int> t = {startTime[i], endTime[i], profit[i]};
            arr.push_back(t);
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        return dfs(arr, 0, dp);
    }
};
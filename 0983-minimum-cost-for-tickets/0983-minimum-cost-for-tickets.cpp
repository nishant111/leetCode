class Solution {
public:
    int maxi;
    int mini;
    vector<int> dp;
    int dfs(vector<int>& days, vector<int>& costs, int curr, int daysCovered) {
        if(curr==days.size()-1) {
            if(days[curr] <= daysCovered)
                return 0;
            else   
                return mini ;
            // base case
        }
        
        //remainingDays--;
        int spent = 0;
        if(days[curr] <= daysCovered) {
            return dfs(days, costs, curr+1, daysCovered);
        }
        if(dp[curr]!=-1) return dp[curr];
        
        spent = min(min(costs[0] + dfs(days, costs, curr+1, days[curr]),
                    costs[1] + dfs(days, costs, curr+1, days[curr] + 6 ) ),
                    costs[2] + dfs(days, costs, curr+1, days[curr] + 29));
        
        return dp[curr] = spent;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size()+1, -1);
        mini = INT_MAX;
        maxi = INT_MIN;
        for(auto elem:costs) {
            mini = min(mini, elem);
            maxi = max(maxi, elem);
        }
        return dfs(days, costs, 0, 0);
    }
};
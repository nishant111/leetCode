class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& sat, int curr, int currTime) {
        if(curr == sat.size()) {
            // base case
            return 0;
        }
        if(dp[curr][currTime] != -1) return dp[curr][currTime];
        int cook = sat[curr] * currTime + dfs(sat, curr+1, currTime+1);
        int skip = dfs(sat, curr+1, currTime);

        return dp[curr][currTime] = max(cook, skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        dp.resize(satisfaction.size()+1,vector<int>(satisfaction.size()+1, -1));
        return dfs(satisfaction, 0, 1);
    }
};
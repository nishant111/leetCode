class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& piles, int k, int currPile) {
        if(k==0 || currPile >= piles.size())
        {
            return 0;
        }
        if(dp[k][currPile]!=-1) return dp[k][currPile];
        int currPileSize = piles[currPile].size();
        int maxCanPick = min(k,currPileSize );
        // dont pick move to top elem on next stack
        int ans = 0 + dfs(piles, k,currPile + 1);
        int pick = 0;
        int count = 0;
        for(int i = 0;i<maxCanPick;i++) {
            pick += piles[currPile][i];
            count++;
            int nextAns = dfs(piles, k-count, currPile+1);
            ans = max(pick+nextAns, ans);
        }
        return dp[k][currPile]= ans;


    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize(k+1, vector<int> (piles.size()+1, -1));
        return dfs(piles, k, 0);
    }
};
class Solution {
public:
    /*int dp[1001][2][101];
    int dfs( vector<int>& prices, int k, int buyPrice, int curr)
    {
        int canBuy = (buyPrice > -1?1:0);
        if(curr == prices.size() && buyPrice != -1)
        {
            return (0-buyPrice);
        }
        
        if(curr == prices.size() && buyPrice == -1)
        {
            return 0;
        }
        
        if(dp[curr][canBuy][k]!=-1) return dp[curr][canBuy][k]; 
        int profit = 0;
        if(k>0 && buyPrice == -1)
        {
            //can buy or choose not to buy;
            profit = max(profit , max(dfs(prices, k-1, prices[curr], curr+1), dfs(prices, k, buyPrice, curr+1)) );
        }
        
        else if(buyPrice != -1)
        {
            //can sell or choose not to sell
            profit = max(profit, max( prices[curr]-buyPrice + dfs(prices, k, -1, curr+1), dfs(prices, k, buyPrice, curr+1)));
        }
        return dp[curr][canBuy][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return(dfs(prices, k, -1, 0));
    }*/
    
    // taken from discuss
    	int solve(int ind, int canBuy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp) {
		if(ind == n || cap == 0)
			return 0;

		if(dp[ind][canBuy][cap] != -1)
			return dp[ind][canBuy][cap];

		int profit = 0;

		if(canBuy == 1) {
			int buy = -prices[ind] + solve(ind+1, 0, cap, prices, n, dp);
			int notBuy = 0 + solve(ind+1, 1, cap, prices, n, dp);
			profit = max(buy, notBuy);
		} else {
			int sell = prices[ind] + solve(ind+1, 1, cap-1, prices, n, dp);
			int notSell = 0 + solve(ind+1, 0, cap, prices, n, dp);
			profit = max(sell, notSell);
		}

		return dp[ind][canBuy][cap] = profit;
	}

    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
		return solve(0, 1, k, prices, n, dp);
    }
};
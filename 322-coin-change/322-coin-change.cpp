class Solution {
    
public:
    
    int dfs(vector<int> &coins, int amount,
           vector<int>& dp)
    {
        
        if(amount == 0)
        {
            return 0;
        }
        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        for(auto coin:coins)
        {
            if(amount-coin>=0)
                ans = min(ans+0LL, dfs(coins, amount-coin, dp)+1LL );
        }
        return dp[amount] = ans ;
    }
    int coinChange(vector<int>& coins, int amount) {
       
        
        vector<int> dp(amount+1, -1);
         int tmp = dfs(coins, amount, dp);
        if(tmp == INT_MAX) return -1;
        else return tmp;
        //return (cnt==INT_MAX?-1:cnt);
    }
};




/*class Solution {
public:
    int dfs(vector<int> &coins, int curr, int amount,
             vector<vector<int>> &dp, int count)
    {
        if(amount <0 || curr >= coins.size())
        {
             cout <<"returning base -1"<<"\n";
            return INT_MAX;
        }
        if(amount == 0)
        {
            //cnt = min(cnt, count);
            cout <<"returning base "<<count<<"\n";
            return count;
        }
        if(dp[curr][amount]!=-1) return dp[curr][amount];
        
        //pick
        int pick = dfs(coins, curr, amount - coins[curr], dp, count+1);
       
        //not Pick
        int nonpick = dfs(coins, curr + 1, amount, dp, count);
       
        cout <<"returning func "<<min(pick, nonpick)<<"\n";
        return dp[curr][amount] = (pick<=nonpick?pick:nonpick); 
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector <int>> dp(coins.size(),vector<int>(amount+1, -1));
        int tmp = dfs(coins, 0, amount, dp,0);
        if(tmp == INT_MAX) return -1;
        else return tmp;
        //return (cnt==INT_MAX?-1:cnt);
    }
};*/
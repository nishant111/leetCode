class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell= -1;
        int profit = INT_MIN;
        for(int i = 1;i<prices.size();i++)
        {
            if(prices[i]>prices[buy])
            {
                sell = i;
                int tmp = prices[i]-prices[buy];
                profit = max(profit, tmp);
            }
            else if(prices[i]<prices[buy])
            {
                // found better price to buy
                buy = i;
            }
        }
        if(profit == INT_MIN)
            return 0;
        else
            return profit;
    }
};
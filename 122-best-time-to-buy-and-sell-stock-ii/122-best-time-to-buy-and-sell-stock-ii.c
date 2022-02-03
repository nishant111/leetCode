

int maxProfit(int* prices, int pricesSize){
    /* fun fact short selling is not allowed :p */
    if (pricesSize == 0)
        return 0;
    if (pricesSize == 1)
        return 0;
    int buy = 0;
    int sell = 1;
    int profit = 0;
    while(sell<pricesSize)
    {
        if(prices[sell] <= prices[buy] )
        {
            buy = sell;
            sell ++;
        }
        else if(prices[sell]>prices[buy])
        {
            profit += prices[sell] - prices[buy];
            buy = sell;
            sell++;
        }
        
    }
    return profit;
}
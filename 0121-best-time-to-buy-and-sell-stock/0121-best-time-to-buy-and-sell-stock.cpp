class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bp = INT_MAX;
        int sp = INT_MIN;
        int ans = 0;
        for(auto elem:prices){
            if(elem<bp){
                bp = elem;
            }
            else{
                ans = max(ans, elem-bp);
            }
        }
        return ans;
    }
};
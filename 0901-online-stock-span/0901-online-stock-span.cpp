class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.size()==0)
        {
            st.push({price,1});
            return 1;
        }
        else
        {
            int ans=1;
            while(!st.empty() && st.top().first<=price)
            {
                auto curr=st.top();
                ans += curr.second;
                st.pop();
                
            }
            st.push({price, ans});
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */